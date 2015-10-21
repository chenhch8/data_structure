enum ErrorCode {success, underflow, overflow};

const int maxStack = 100;             // ջ���������

template <class StackEntry>
class MyStack {
 public:
    MyStack(): size(0) {}
         /*�ж�ջ�Ƿ�Ϊ�գ���Ϊ���򷵻�true���ǿ��򷵻�false */
    bool empty() const {return size == 0;}

         /*��ջ��������������ջ�򷵻�success����ջ����Ԫ���򷵻�underflow*/
    ErrorCode pop() {
        if (size == 0)
            return underflow;
	size--;
	return success;
    }

        /* ��ȡջ��Ԫ�أ���������ջ�򷵻�success����ջ����Ԫ���򷵻�underflow
           Ԫ�����ݱ��������ò���item��*/
    ErrorCode top(StackEntry &item) const {
        if (size > 0) {
	    item = entry[size];
	    return success;
	} else {
	    return underflow;
	}
    }

         /* ��ջ��������������ջ�򷵻�success����ջ���򷵻�overflow*/
    ErrorCode push(const StackEntry &item) {
        if (size < maxStack) {
	    entry[size++] = item;
	    return success;
	} else {
	    return overflow;
	}
    }
 private:
    int size;
    StackEntry entry[maxStack];
};
