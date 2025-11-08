// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.0;

contract StudentData{

    //Structure

    struct Student{
        string name;
        uint rollNo;
    }

    //Array

    Student[] public studentArr;

    function addStudent(string memory name,uint rollNo) public  {
        for(uint i = 0;i<studentArr.length;i++){
            if(studentArr[i].rollNo == rollNo){
                revert("Student already exists");
            }
        }
        studentArr.push(Student(name,rollNo));
    }

    function getLen() public view returns(uint){
        return studentArr.length;
    }

    function displayAll() public view returns(Student [] memory){
        return studentArr;
    }

    function getStudentByIdx(uint idx) public view returns(Student memory){
        
        require(idx < studentArr.length, "Index out of bounds");
        return studentArr[idx];
    }

    //Fallback

    fallback() external payable {
        //Handle external function calls
    }

    receive() external payable {
        //Handle ether sent by external users
    }
}