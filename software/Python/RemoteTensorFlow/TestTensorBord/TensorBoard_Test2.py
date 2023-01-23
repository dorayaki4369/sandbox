# このプログラムはqiitaに投稿されていた記事のもうちょっと複雑な例を元に、
# TensorFlow1.1.0
# Python3.X
# で動作するように書き換えたものです。
# 
# 参考サイト:
# http://qiita.com/supersaiakujin/items/aa598c942c3ec82d0c8c#code-1
# 
# ログファイル出力場所
# /home/hirayama/tensorflow-workspace/log/mnist

import tensorflow as tf
import input_data #同じ場所にinput_data.pyを置くこと
import setting

setting = setting.Setting();

print('load MNIST dataset')
mnist = input_data.read_data_sets("MNIST_data", one_hot=True)

def weight_variable(shape):
    initial = tf.truncated_normal(shape, stddev=0.1)
    return tf.Variable(initial)

def bias_variable(shape):
    initial = tf.constant(0.1, shape = shape)
    return tf.Variable(initial)

def conv2d(x, W):
    return tf.nn.conv2d(x, W, strides=[1,1,1,1], padding='SAME')
def max_pool_2x2(x):
    return tf.nn.max_pool(x, ksize=[1,2,2,1], strides=[1,2,2,1], padding='SAME')

def _write_summary_histogram(parent, infos):
    for i in infos:
        tf.summary.histogram("%s/%s" % (parent, i[0]), i[1])

with tf.Session() as sess:
    x = tf.placeholder("float", [None, 784])
    y_ = tf.placeholder("float", [None, 10])

    # 1x28x28 -> 32x28x28 -> 32x14x14
    x_image = tf.reshape(x, [-1,28,28,1])    
    with tf.variable_scope('conv1') as scope:
        W_conv1 = weight_variable([5, 5, 1, 32])
        b_conv1 = bias_variable([32])
        h_conv1 = tf.nn.relu(conv2d(x_image, W_conv1) + b_conv1, name=scope.name)

        _write_summary_histogram('conv1', [['weights', W_conv1],['biases', b_conv1], ['activations', h_conv1]])

    h_pool1 = max_pool_2x2(h_conv1)  

    # 32x14x14 -> 64x7x7
    with tf.variable_scope('conv1') as scope:
        W_conv2 = weight_variable([5, 5, 32, 64])
        b_conv2 = bias_variable([64])
        h_conv2 = tf.nn.relu(conv2d(h_pool1, W_conv2) + b_conv2, name=scope.name)

        _write_summary_histogram('conv2', [['weights', W_conv2],['biases', b_conv2], ['activations', h_conv2]])

    h_pool2 = max_pool_2x2(h_conv2)    

    # 64x7x7 -> 1024
    with tf.variable_scope('full1') as scope:
        W_fc1 = weight_variable([7 * 7 * 64, 1024])
        b_fc1 = bias_variable([1024])
        h_pool2_flat = tf.reshape(h_pool2, [-1, 7*7*64])
        h_fc1 = tf.nn.relu(tf.matmul(h_pool2_flat, W_fc1) + b_fc1, name=scope.name)    

        _write_summary_histogram('full1', [['weights', W_fc1],['biases', b_fc1], ['activations', h_fc1]])

    # dropout
    keep_prob = tf.placeholder("float")
    h_fc1_drop = tf.nn.dropout(h_fc1, keep_prob)

    # Readout
    with tf.variable_scope('full2') as scope:
        W_fc2 = weight_variable([1024, 10])
        b_fc2 = bias_variable([10])

        y_conv=tf.nn.softmax(tf.matmul(h_fc1_drop, W_fc2) + b_fc2, name=scope.name)  

        _write_summary_histogram('full2', [['weights', W_fc2],['biases', b_fc2]])

    tf.summary.histogram("y", y_conv)

    cross_entropy = -tf.reduce_sum(y_*tf.log(y_conv))

    train_step = tf.train.AdamOptimizer(1e-4).minimize(cross_entropy)
    correct_prediction = tf.equal(tf.argmax(y_conv,1), tf.argmax(y_,1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))


    tf.summary.scalar("cross_entropy", cross_entropy)
    tf.summary.scalar("accuracy", accuracy)

    # Before starting, initialize the variables.  We will 'run' this first.
    init = tf.global_variables_initializer()

    # Creates a SummaryWriter
    # Merges all summaries collected in the default graph
    merged = tf.summary.merge_all()
    writer = tf.summary.FileWriter(setting.getLogFilePass("mnist"), sess.graph)

    sess.run(init)

    # training
    N = len(mnist.train.images)
    N_test = len(mnist.test.images)
    n_epoch = 20000
    batchsize = 50

    for i in range(n_epoch):
        batch = mnist.train.next_batch(batchsize)
        if i%100 == 0:
            summary_str, loss_value = sess.run([merged, accuracy], feed_dict={x: batch[0], y_: batch[1], keep_prob: 0.5})
            writer.add_summary(summary_str, i)
            print("step %d %.2f" % (i, loss_value))
        sess.run(train_step, feed_dict={x: batch[0], y_: batch[1], keep_prob: 0.5})    

    tacc = 0
    tbatchsize = 1000
    for i in range(0,N_test,tbatchsize):
        acc = sess.run(accuracy, feed_dict={
        x: mnist.test.images[i:i+tbatchsize], y_: mnist.test.labels[i:i+tbatchsize], keep_prob: 1.0})
        tacc += acc * tbatchsize

        print("test step %d acc = %.2f" % (i//tbatchsize, acc))
    tacc /= N_test
    print("test accuracy %.2f" % tacc)
