import tensorflow as tf
import setting as s

setting = s.Setting()

# 定数で1 + 2
x = tf.constant(1, name='x')
y = tf.constant(2, name='y')
z = x * y + y

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    sess.run(z)
    # SummaryWriterでグラフを書く
    summary_writer = tf.summary.FileWriter(setting.getLogFilePass("board1"), graph=sess.graph)
    tf.summary.scalar('one_plus_one_summary', z)
