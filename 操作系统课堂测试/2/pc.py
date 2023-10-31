mutex = Semaphore(1)  # 互斥锁，用于对仓库的访问进行保护
empty = Semaphore(1)  # 空仓库信号量，初始值为1，表示仓库中没有产品
full = Semaphore(0)  # 满仓库信号量，初始值为0，表示仓库中没有产品

A_count = 0  # 产品A数量
B_count = 0  # 产品B数量
N = 5  # 最小差值
M = 10  # 最大差值


# 生产者进程
def producer():
    global A_count, B_count
    while True:
        # 随机生成一个产品类型
        product_type = random.choice(["A", "B"])
        if product_type == "A":
            # 等待空仓库
            empty.wait()
            # 获取互斥锁
            mutex.wait()
            # 将产品A放入仓库中
            A_count += 1
            print("生产者生产了一个A产品，当前A产品数量为", A_count)
            # 检查产品数量是否符合要求
            if N < A_count - B_count < M:
                # 释放互斥锁
                mutex.signal()
                # 通知消费者可以消费产品了
                full.signal()
            else:
                # 释放互斥锁
                mutex.signal()
        else:
            # 等待空仓库
            empty.wait()
            # 获取互斥锁
            mutex.wait()
            # 将产品B放入仓库中
            B_count += 1
            print("生产者生产了一个B产品，当前B产品数量为", B_count)
            # 检查产品数量是否符合要求
            if N < A_count - B_count < M:
                # 释放互斥锁
                mutex.signal()
                # 通知消费者可以消费产品了
                full.signal()
            else:
                # 释放互斥锁
                mutex.signal()


# 消费者进程
def consumer():
    global A_count, B_count
    while True:
        # 等待满仓库
        full.wait()
        # 获取互斥锁
        mutex.wait()
        # 取出一个产品
        if A_count > B_count:
            A_count -= 1
            print("消费者消费了一个A产品，当前A产品数量为", A_count)
        else:
            B_count -= 1
            print("消费者消费了一个B产品，当前B产品数量为", B_count)
        # 检查产品数量是否符合要求
        if N < A_count - B_count < M:
            # 释放互斥锁
            mutex.signal()
            # 通知生产者可以生产产品了
            empty.signal()
        else:
            # 释放互斥锁
            mutex.signal()


# 创建生产者和消费者进程
p1 = Process(target=producer)
p2 = Process(target=consumer)
p1.start()
p2.start()
