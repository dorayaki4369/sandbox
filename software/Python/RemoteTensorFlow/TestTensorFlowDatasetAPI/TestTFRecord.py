# MNISTを使ってTFRecordを試す

import numpy as np
import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data


def make_example(image, label):
    return tf.train.Example(features=tf.train.Features(feature={
        'image': tf.train.Feature(bytes_list=tf.train.BytesList(value=[image])),
        'label': tf.train.Feature(bytes_list=tf.train.BytesList(value=[label])),
    }))


def write_tfrecord(images, labels, filename):
    writer = tf.python_io.TFRecordWriter(filename)
    for image, label in zip(images, labels):
        labels = labels.astype(np.float32)
        ex = make_example(image=image.tobytes(), label=label.tobytes())
        writer.write(ex.SerializeToString())
    writer.close()


def main():
    mnist = input_data.read_data_sets('data/mnist', one_hot=True)
    train_images = mnist.train.images
    train_labels = mnist.train.labels
    test_images = mnist.test.images
    test_labels = mnist.test.labels
    write_tfrecord(train_images, train_labels, 'mnist_train.tfrecord')
    write_tfrecord(test_images, test_labels, 'mnist_test.tfrecord')


if __name__ == '__main__':
    main()
