# LeNet 基于 CIFAR-10 的图像分类项目

## 1. 项目简介
本项目基于 LeNet 网络结构，在 CIFAR-10 数据集上进行图像分类任务。LeNet 是一个经典的卷积神经网络（CNN）模型，最早用于手写数字识别，本次实验通过 CIFAR-10 数据集进一步了解 CNN 的工作原理和应用。

## 2. CIFAR-10 数据集
CIFAR-10 是一个常见的图像分类数据集，包含 60000 张 32x32 彩色图像，共分为 10 个类，分别是：飞机、汽车、鸟、猫、鹿、狗、青蛙、马、船、卡车。训练集中有 50000 张图像，测试集中有 10000 张图像。

## 3. LeNet 模型结构
LeNet 模型由两个卷积层、两个池化层、两个全连接层和一个输出层组成。该模型适合处理小型图像分类任务。

- **卷积层1**：6 个 5x5 的卷积核，使用 ReLU 激活函数。
- **池化层1**：平均池化层，2x2 池化窗口。
- **卷积层2**：16 个 5x5 的卷积核，使用 ReLU 激活函数。
- **池化层2**：平均池化层，2x2 池化窗口。
- **全连接层1**：120 个神经元，使用 ReLU 激活函数。
- **全连接层2**：84 个神经元，使用 ReLU 激活函数。
- **输出层**：10 个类别，使用 softmax 输出概率。

## 4. 实现代码

### 4.1 数据加载和预处理
```python
from tensorflow.keras import datasets

(x_train, y_train), (x_test, y_test) = datasets.cifar10.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0
### 4.2完整的代码
# 导入所需的库
import tensorflow as tf
from tensorflow.keras import datasets, layers, models
import matplotlib.pyplot as plt

# 加载 CIFAR-10 数据集，并进行归一化处理
(x_train, y_train), (x_test, y_test) = datasets.cifar10.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0

# 定义 LeNet 模型
def build_lenet():
    model = models.Sequential()

    # 第一个卷积层和池化层
    model.add(layers.Conv2D(6, (5, 5), activation='relu', input_shape=(32, 32, 3)))
    model.add(layers.AveragePooling2D(pool_size=(2, 2)))  # 添加池化窗口大小

    # 第二个卷积层和池化层
    model.add(layers.Conv2D(16, (5, 5), activation='relu'))
    model.add(layers.AveragePooling2D(pool_size=(2, 2)))  # 添加池化窗口大小

    # 全连接层和输出层
    model.add(layers.Flatten())
    model.add(layers.Dense(120, activation='relu'))
    model.add(layers.Dense(84, activation='relu'))
    model.add(layers.Dense(10, activation='softmax'))

    return model

# 构建模型
model = build_lenet()

# 编译模型
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

# 训练模型
history = model.fit(x_train, y_train, epochs=10, validation_data=(x_test, y_test))

# 在测试集上评估模型
test_loss, test_acc = model.evaluate(x_test, y_test, verbose=2)
print(f"Test accuracy: {test_acc}")

# 可视化训练和验证过程中的准确率
plt.plot(history.history['accuracy'], label='accuracy')
plt.plot(history.history['val_accuracy'], label='val_accuracy')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.ylim([0, 1])
plt.legend(loc='lower right')
plt.show()
