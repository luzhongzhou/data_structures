/*
*完美世界 2017实习生招聘笔试 第一道编程题
*输入四个整数： w h x n
*其中w和h是宽和高，一个小球从（x,0）处沿右上方45度弹走。
*输出是n个整数，依次是小球与x轴的交点。
*如果弹到角落里，反向弹出。
*/
#include <stdio.h>

typedef struct point{
	int x;
	int y;
}point;

typedef struct line{
	point p;
	int k;
}line;

point get_cross(line l, int w, int h){
	//找出与四个边的交点，再筛选
	point p_xw;
	point p_yh;
	point p_x0;
	point p_y0;

	p_xw.x = w;
	p_xw.y = l.k*(w - l.p.x) + l.p.y;

	p_yh.x = (h - l.p.y)/l.k + l.p.x;
	p_yh.y = h;

	p_x0.x = 0;
	p_x0.y = l.p.y - l.k*l.p.x;

	p_y0.x = l.p.x - l.p.y/l.k;
	p_y0.y = 0;

	if(p_xw.y >= 0 && p_xw.y <= h && p_xw.y != l.p.y){
		return p_xw;
	}
	else if(p_yh.x >= 0 && p_yh.x <= w && p_yh.x != l.p.x){
		return p_yh;
	}else if(p_x0.y >=0 && p_x0.y <= h && p_x0.y != l.p.y){
		return p_x0;
	}else return p_y0;
}

int p_eq(point a, point b){
	if(a.x == b.x && a.y == b.y) return 1;
	else return 0;
}

void ball(int w, int h, int x, int n){
	//x < n
	line l;
	l.p.x = x;
	l.p.y = 0;
	l.k = 1;	
	
	//四个顶点
	point zz;
	zz.x = 0;
	zz.y = 0;
	point wz;
	wz.x = w;
	wz.y = 0;
	point wh;
	wh.x = w;
	wh.y = h;
	point zh;
	zh.x = 0;
	zh.y = h;

	line new_l;
	while(n > 0){
		new_l.p = get_cross(l, w, h);
		if(new_l.p.y == 0){
			n--;
			printf("%d ",new_l.p.x);
		}
		if(p_eq(new_l.p, zz) || p_eq(new_l.p, wz)||p_eq(new_l.p,wh)||p_eq(new_l.p,zh))
			new_l.k = l.k;
		new_l.k = -1/l.k;
		l = new_l;
	}		
	printf("\n");
}

int main(){
	int w, h, x, n;
	while(scanf("%d%d%d%d", &w, &h, &x, &n) != EOF){
		ball(w, h, x, n);
	}
}
