function [date] = readInputS()
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

fileID = fopen('inputS.txt','r');
c = textscan(fileID, '%s %f');
date = c{1};
fclose(fileID);

end

