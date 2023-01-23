# tensorflow1.3より追加されたDatasetAPIの試し
# 0~9までのデータを作成している。

import tensorflow as tf
dataset = tf.contrib.data.Dataset.range(10)
iterator = dataset.make_one_shot_iterator()
next_element = iterator.get_next()
sess = tf.InteractiveSession()
for i in range(10):
    print(sess.run(next_element))

# 例外発生
print(sess.run(next_element))
