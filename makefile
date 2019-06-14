park:main.cpp ./lib/myqueue.cpp ./lib/mystack.cpp ./show/show.cpp ./order/order.cpp
	g++ main.cpp ./lib/myqueue.cpp ./lib/mystack.cpp ./show/show.cpp ./order/order.cpp\
 -o park -I ./lib -I ./show -I ./order
clean:
	rm -f *~  
