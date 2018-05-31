%Author : Ibrahim Saad
%Task   : Resize an image size to the half size

%we take average of every 4 adjacent pixels and then assign average to the
%correspond pixel in the new image
%this function is practical with only binary and grayscale images 

function [newImage] = ImageResize(im)
if size(im,3) == 1
    [M, N] = size(im);

    %if width or height is odd add r or c with zeros values
    if rem(M, 2) == 1
        M = M + 1;
        im(M, :) = 0;
    end
    
    if rem(N, 2) == 1
        N = N + 1;
        im(:, N) = 0;
    end

    newImage = zeros(M/2, N/2);
    nr = 1; nc = 1;

    %every pixel in new image = average(4 adjacent pixels)
    for r = 1:2:M
        for c = 1:2:N
            window = im([r, r+1],[c, c+1]);
            newImage(nr, nc) = mean(window(:));
            nc = nc + 1 ;
        end
        nr = nr + 1;
        nc = 1;
    end
end
end    