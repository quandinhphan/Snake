I Phần Snake.cpp

khai báo biến toàn cục window, renderer, texture(để load ảnh), surface;

khai báo chiều dài chiều rộng của màn hình và tên của window;

SDL_Texture* LoadTexture để load ảnh ,vẽ ảnh lên texture;
SDL_Rect SourceRect để lấy giá trị tọa độ , chiều cao và chiều rộng của ảnh load vào;
SDL_Rect desRect xác định tọa đồ cũng như chiều cao và chiều rộng của texture mà ta vẽ lên màn hình;

HÀM MAIN

khai báo sự kiện 
load 5 ảnh png và lấy thông tin của nó;

vòng lặp while{
	Menurunning để menu chạy
	nếu như ấn esc hoặc nhấn quit thì sẽ out chương trình;
	không thì sẽ vào phần chọn mode{
		nếu ấn esc thì ra lại chỗ menu{
		ấn w để chơi classic mode ấn s để chơi box mode{
			thua thì sẽ quay về chọn chế độ}
	}
}

phá hủy 5 texture;
quit SDL phá hủy bút vẽ và window;



II Phần SDL_utils.cpp
có hàm khởi tạo bút vẽ window , hàm báo lỗi không dùng đc SDL , hàm đợi 1 phím, hàm xóa bút vẽ và window;


III Phần game.cpp

1)void Gameplay
hàm này chuyền vào biến bút vẽ , texture1 của ảnh 1, SDL_Rect SourceRect1, SDL_Rect desRect1 của texture1 để vẽ và 
chuyên vào 1 số (0 hoặc 1) nếu là 1 thì là vẽ gameplay cho classic ,0 thì vẽ game play cho box;
khai báo sự kiện;

	khai báo box là sân chơi của con rắn;
	-khai báo mảng kiểu Cycle có 30 phần tử;
	-khai báo tọa độ của cycle[0] là đầu con rắn;
	-khai báo tọa độ của con mồi đầu tiên;
	-snakepoint là số đốt mà rắn có ban đầu con rắn có 1 đốt;
	-vòng lặp while với điều kiên là dem=0 vì ở dưới có vòng for nếu tọa độ của 2 điểm trên thân rắn bằng nhau thì dem++ và điều đó
	đồng nghĩa với việc con rắn cắn bản thân mình;

	-eating để kiểm tra nếu như tọa độ của con mồi bằng với tọa độ của đầu rắn thì rắn tăng tốc và thay đổi con mồi và rắn tăng thêm 1 đốt;
	-nếu như là classic thì cycle[0].goback để con rắn không chạy ra ngoài sân;
	-nếu như là box thì cycle[0].hitthewall() để con rắn chết khi đâm vào tường;

	-lưu tọa độ của cycle[0] vào x0 và y0;
	-vong lặp for sao cho tọa độ của cycle sau phải bằng tọa độ của cycle trước trước khi nó di chuyển;
	tóm lại các cycle sau di chuyển theo cycle trước và cycle[0] là cycle di chuyển tự do;
	-in ra tọa độ của đầu rắn và con mồi để xem có khi nào con rắn không ăn được mồi 
	-đặt lại màu;
	-xóa màn hình;
	-vẽ sân chơi
	-vẽ con mồi;
	-sau đó vẽ con rắn;
	-vẽ ảnh 1 vừa load;
	-hiện những gì đã vẽ ra màn hình;
	-delay(speedtime) 
	-sau mỗi lần ăn được mồi thì speedtime giảm để con rắn tăng tốc;
	-các câu lệnh điều khiển con rắn qua bàn phím;

2)void Menurunning để vẽ ảnh 2 (ảnh này là menu);


IV Phần shape.h 
xsquare và ysquare là tọa độ của hình chứ nhật , wsquare và hsquare là chiều rộng và chiều dài
hình chứ nhật chính là sân chơi của con rắn

stepchange là các bước của con rắn và nó bằng đường kính của một đốt trên con rắn;


kiểu dữ liệu Cycle{
	có x và y là tọa độ và x0 và y0 cũng là tọa độ nhưng sẽ nói đến ở sau;
	mỗi điểm trên rắn có bán kính là 5;
	stepX=0 và StepY=0 để con rắn đứng yên khi mới chạy chương trình;
	-Hàm thành viên render để vẽ hình tròn với viền ngoài màu xanh;
	-hàm thành viên move giúp di chuyển con rắn, các hàm moveup, movedown,moveright,moveleft để chuyển hướng;
	-hàm goback để con rắn nếu đi ra ngoài thì sẽ quay lại ở bên kia màn hình;
	-hàm hitthewall để kiểm tra xem rắn có đâm vào tường không;
	-hàm createFood để tạo con mồi, con mồi phải có tọa độ chia hết cho stepchange để con rắn có thể ăn được;

	kiểu dữ liệu struct Box để vẽ hình chữ nhật là sân chơi cho con rắn;
	hàm runfaster để làm m giảm m là số miligiay delay m càng giảm rắn càng nhanh;
	hàm eating để kiểm tra xem con rắn có ăn được mồi hay chưa nếu ăn được thì tăng tốc và tạo ra một con mồi mới;

	

	
	
