import tensorflow as tf
from tensorflow.contrib import slim
from tensorflow.examples.tutorials.mnist import input_data

with tf.Graph().as_default() as graph:
    mnist = input_data.read_data_sets('MNIST_data', one_hot=True)
    x = tf.placeholder(tf.float32, shape=[None, 784])
    y = tf.placeholder(tf.float32, shape=[None, 10])
    x_train = tf.reshape(x, [-1, 28, 28, 1])
    tf.summary.image('input', x_train, 10)

    with slim.arg_scope([slim.conv2d, slim.fully_connected],
            normalizer_fn=slim.batch_norm,
            activation_fn=tf.nn.relu):
        with slim.arg_scope([slim.max_pool2d], padding='SAME'):
            conv1 = slim.conv2d(x_train, 32, [5, 5], scope='conv1')
            conv_vars = tf.get_collection(tf.GraphKeys.MODEL_VARIABLES, 'Conv')
            tf.summary.histogram('conv_weights', conv_vars[0])
            pool1 = slim.max_pool2d(conv1, [2, 2])
            conv2 = slim.conv2d(pool1, 64, [5, 5])
            pool2 = slim.max_pool2d(conv2, [2, 2])
            flatten = slim.flatten(pool2)
            fc = slim.fully_connected(flatten, 1024)

    logits = slim.fully_connected(fc, 10, activation_fn=None)
    softmax = tf.nn.softmax(logits, name='output')

    with tf.name_scope('loss'):
        loss = slim.losses.softmax_cross_entropy(logits, y)
        tf.summary.scalar('loss', loss)

    train_op = slim.optimize_loss(loss, slim.get_or_create_global_step(),
            learning_rate=0.01,
            optimizer='Adam')

    correct_prediction = tf.equal(tf.argmax(logits, 1), tf.argmax(y, 1))
    with tf.name_scope('accuracy'):
        accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
        tf.summary.scalar('accuracy', accuracy)

    summary = tf.summary.merge_all()

with tf.Session() as sess:
    writer = tf.summary.FileWriter('cnn', sess.graph)
    sess.run(tf.global_variables_initializer())
    sess.run(tf.local_variables_initializer())
    for i in range(500):
        batch = mnist.train.next_batch(50)
        if i % 100 == 0:
            train_accuracy = accuracy.eval(feed_dict={x:batch[0], y:batch[1]})
            print("step %d, training accuracy %g"%(i, train_accuracy))
        _, w_summary = sess.run([train_op, summary], feed_dict={x:batch[0], y:batch[1]})
        writer.add_summary(w_summary, i)