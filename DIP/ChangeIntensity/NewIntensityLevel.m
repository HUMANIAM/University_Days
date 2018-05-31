%Author : Ibrahim saad
%Task   : change Intensity level of an image

%this function changes the intensity level of specific image to new
%intensity level as example from 0-255 to 0-128 to 0-64
%find the max level of the image then divide all pixels by this max
%intesity and then multiply the ratio image by the new max level

function [newImage] = NewIntensityLevel(im, ratio)

imClass  = class(im);
%maxIntensity = 0.0;
isDouble = length(strfind(imClass, 'double'));
isInt    = length(strfind(imClass, 'int'));
isSingle = length(strfind(imClass, 'single'));

%determine the type of the class to find the max value of this type
if isInt
    
    maxIntensity = intmax(imClass);
    
elseif isDouble || isSingle
    
    maxIntensity = realmax(imClass);
    
else
    maxIntensity = 1;
end

%ratio of pixel intensity to max level intensity of the image
newlevle = maxIntensity * ratio;
newImage = (im / maxIntensity) * newlevle;

end