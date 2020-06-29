class CQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def appendTail(self, value: int) -> None:
        self.stack1.append(value)

    def deleteHead(self) -> int:
        if len(self.stack2) == 0:
            if len(self.stack1) == 0:
                return -1
            else:
                while len(self.stack1):
                    self.stack2.append(self.stack1[-1])
                    self.stack1.pop()
        num = self.stack2[-1]
        self.stack2.pop()
        return num



# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()