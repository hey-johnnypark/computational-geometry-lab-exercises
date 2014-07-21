
% M = tdfread('testpolygon.txt','\t');
% 
% x = getfield(M, 'x_x_y');
% [D,IDX]  = bwdist(x);
% D1 = bwdist(x,'euclidean');
% xValues = x(:,1);
% yValues = x(:,2);
% figure;
% plot(xValues,yValues,'*');
% fill(xValues,yValues,'green') ;
% axis([-10,20,-10,20]);
%subplot(2,2,1), subimage(mat2gray(D1)), title('Euclidean');
%hold on, imcontour(D1);

A = dataset('File','polygon.txt',  'delimiter', '\t', 'ReadVarNames', 'off');
xArray =double(A(:,2));
yArray = double(A(:,3));
figure;
plot(xArray,yArray,'*');
pointsArray(1,:) = xArray;
pointsArray(2,:) = yArray;
pointsArrayRotate = rot90(pointsArray);
[C,R] = incircle(xArray,yArray);
fill(xArray,yArray,'red') ;
drawCircle(C(1,1),C(1,2),R);



% D1 = bwdist(pointsArrayRotate,'euclidean');
% subimage(mat2gray(D1)), title('Euclidean');
%hold on, imcontour(pointsArrayRotate);
