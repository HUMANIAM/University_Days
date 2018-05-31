function [ newimage ] = Filter( image, type )
%check if it high or low or band or reject pass filter
%using ringing affect filter
if strcmp(type, 'low') || strcmp(type, 'high')
   im =  LO_HIFileter(image, type);
   newimage = im2uint8(im);
   
elseif  strcmp(type, 'band')
    imh = LO_HIFileter(image, 'high');
    iml = LO_HIFileter(image, 'low');
    im = imh .* iml;
    newimage = im2uint8(im);
end

end

function [Fimage] = LO_HIFileter(image, type)
    %using a circle as mask window with high pass filter or low pass filter
    %where the original image is 256*256
    [x, y] = meshgrid(-128:127, -128:127);
    z = sqrt(x.^2 + y.^2);
    if strcmp(type, 'high')
        wnd = z>15;
    else
        wnd = z<10;
    end
    %image in frequency domain
    ImageFD = fftshift(fft2(image));
    %filtered image
    Fimage = ImageFD .* wnd;
    %return image again to the spatial domain
    SDimage = ifft2(Fimage);
    Fimage = abs(SDimage/max(SDimage(:)));
end