T*   allocate(int n);           // дай n слотов сырой памяти под T

void deallocate(T* p, int n);   // верни эти n слотов обратно

void construct(T* p, ...);      // создай T в слоте p

void destroy(T* p);             // разрушь T в слоте p

новый параметр A и alloc.allocate/deallocate;

AT::construct / AT::destroy вместо устаревших alloc.construct/destroy;

uninitialized_copy вместо copy;

разделение «destroy → deallocate» в деструкторе, reserve, resize, перемещающем присваивании;

construct в push_back вместо присваивания;

copy-and-swap в копирующем присваивании (появилось в главе 19).