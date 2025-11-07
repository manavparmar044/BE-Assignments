// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract Bank{
    uint256 balance = 0;
    address public accOwner;

    constructor(){
        accOwner = msg.sender;
    }
    //Deposit
    function deposit() public payable {
        require(accOwner == msg.sender,"You are not an account owner");
        require(msg.value > 0, "Amount should be positive");
        balance += msg.value;
    }
    //Withdraw
    function withDraw() public payable {
        require(accOwner == msg.sender,"You are not an account owner");
        require(msg.value > 0, "Amount should be positive");
        balance -= msg.value;
    }
    //Show
    function showBalance() public view returns(uint256){
        require(accOwner == msg.sender,"You are not an account owner");
        return balance;
    }
}