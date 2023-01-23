# DatasetAPIを試す
# initializableイテレータは、データセットの作成と処理パイプラインをパラメータ化する

import tensorflow as tf

range_param = tf.placeholder(tf.int64)
dataset = tf.contrib.data.Dataset.range(range_param)
iterator = dataset.make_initializable_iterator()
next_element = iterator.get_next()
sess = tf.InteractiveSession()
sess.run(iterator.initializer, feed_dict={range_param: 10})
for i in range(10):
    print(sess.run(next_element))

sess.run(iterator.initializer, feed_dict={range_param: 30})
for i in range(30):
    print(sess.run(next_element))