function [ A ] = readInputT()
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

fileID = fopen('inputT.txt','r');
formatSpec = '%f';
A = fscanf(fileID,formatSpec);
fclose(fileID);


end

