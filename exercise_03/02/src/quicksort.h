#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

template <class T, std::size_t SIZE>
class Quicksort {
    public:
        static void quicksort(std::array<T, SIZE>& array, int left, int right)
        {
            if (left >= right) {
                return;
            }

            int l = left - 1;
            int r = right;

            while (true) {
                while (array[++l] < array[right]) {
                    if (l >= r) {
                        break;
                    }
                }

                while (array[--r] > array[right]) {
                    if (l >= r) {
                        break;
                    }
                }

                if (l >= r) {
                    break;
                }

                T temp = array[l];
                array[l] = array[r];
                array[r] = temp;
            }

            T temp = array[l];
            array[l] = array[right];
            array[right] = temp;

            Quicksort::quicksort(array, left, l - 1);
            Quicksort::quicksort(array, l + 1, right);
        }
};

#endif /* __QUICKSORT_H__ */
