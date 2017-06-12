
% Read the file.csv 
fid=fopen('nyc_taxi_edit3.csv','r', 'n', 'US-ASCII');
data=textscan(fid,'%f32 %f32','delimiter',',','headerlines',1);
fclose(fid);


% calculate the mean of every column

 mean=zeros(1,2);
size=size(data{1},1);
 mean(1)=sum(data{1})/size;
mean(2)=sum(data{2})/size;

% % calculate the variance of the columns
% 
 squr_diff_mean=zeros(size,2);
 var=zeros(1,2);
 SD=zeros(1,2);
 const=zeros(1,2);
 
for i=1:2
 squr_diff_mean(:,i)=(data{i}-mean(i)).^2;
 var(i)= sum(squr_diff_mean(:,i))/size;
 SD(i)=sqrt(var(i));
 const(i)=1/(SD(i)*sqrt(2*pi));
end
% 

% calculate the probability of every attribute in the data

p=zeros(size,2);
for i=1:size
    p(i,1)=const(1)*exp(-0.5*squr_diff_mean(i,1)/var(1));
    p(i,2)=const(2)*exp(-0.5*squr_diff_mean(i,2)/var(2));
end

%probability of records

probability=zeros(size,1);
probability=p(:,1).*p(:,2);

% plotting the anomaly detection of records

epson=sum(probability)/size;
current_items_state=zeros(size,1);
current_items_state=probability>epson;
D=zeros(size,3);
D(:,1)=data{1};
D(:,2)=data{2};
D(:,3)=current_items_state;

%table of values
%prompt = 'What is the original value? ';
%sprintf(prompt);
% x = input(prompt)
% y = x*10
% 
f=figure;
headers={'timestamp','value','state'};

h = uitable(f,'Data',D, 'ColumnName',headers);





























