// ===== function 0x40b7c0 =====

ulong FUN_0040b7c0(uint *param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = param_1[1];
  uVar2 = (ulong)*param_1 +
          (((ulong)uVar1 & 0xfffffff) * 0x10 + 0x61ca272b ^ (ulong)uVar1 - 0x61c88647 ^
          (ulong)(uVar1 >> 5) - 0x68b4ef1b);
  uVar3 = (ulong)uVar1 +
          ((uVar2 & 0xfffffff) * 0x10 + 0x1c281893 ^ uVar2 - 0x61c88647 ^
          ((uVar2 & 0xffffffff) >> 5) + 0x449beed9);
  uVar2 = ((uVar3 & 0xfffffff) * 0x10 + 0x61ca272b ^ uVar3 + 0x3c6ef372 ^
          ((uVar3 & 0xffffffff) >> 5) - 0x68b4ef1b) + uVar2;
  param_1[1] = (uint)uVar2;
  uVar3 = ((uVar2 & 0xfffffff) * 0x10 + 0x1c281893 ^ uVar2 + 0x3c6ef372 ^
          ((uVar2 & 0xffffffff) >> 5) + 0x449beed9) + uVar3;
  *param_1 = (uint)uVar3;
  return (uVar3 & 0xffffffff) * param_2 >> 0x20;
}



// ===== function 0x281688 =====

undefined4 FUN_00281688(undefined4 param_1,long param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x00283f90((((ulong)*(byte *)(param_2 + 0x838) - 1 & 0xffffffff) >> 0x1f) + 0x710);
  func_0x0074a310(param_1,uVar1);
  return param_1;
}



