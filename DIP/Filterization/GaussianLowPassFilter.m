function [ newImage ] = LowPassFilter( image )
%low pass filter meaning smoothing the image where passing values with 
%smaller frequencies and reject values with high so it is blur the image
%using guassian for lowpass filter with standard deviation 15
wnd = mat2gray(fspecial('gaussian', 256, 15));

%map the image from spatial domain to frequency domain by FFT
Image_FFT = fftshift(fft2(image));
%convolution the filter function with the image in FFT
convimage = Image_FFT .* wnd;

%apply inverse FFT to return back to the spatial domain
iconvimage = ifft2(convimage);

f = abs(iconvimage);
newImage = im2uint8(f/max(f(:)));

end

