'''
@Author: Yaowen Xu
@Github: https://github.com/yaowenxu
@Organization: 北航系统结构研究所
@Date: 2020-02-26 15:12:39
@LastEditTime: 2020-02-26 15:50:34
@Description: 文件描述信息
'''
print("当前版本：", __name__)
# content of test_sample.py
def inc(x):
    return x + 1

def test_answer():
    assert inc(3) == 4