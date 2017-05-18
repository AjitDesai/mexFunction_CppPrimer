function [date amount] = readInputTD()
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

fileID = fopen('inputTD.txt','r');
c = textscan(fileID, '%s %f');
date = c{1}
amount = c{2}
fclose(fileID);

end

