// ===== function 0x679af0 =====

void FUN_00679af0(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar1 = *param_2;
  uVar3 = (ulong)uVar1;
  FUN_00648cc8(param_1,uVar3,0x15);
  FUN_006490a0(param_1,uVar1 + 0x18);
  FUN_006490a0(param_1,uVar1 + 0x1c);
  uVar2 = *(uint *)(uVar3 + 0x1c);
  if ((uVar2 & 4) != 0) {
    FUN_006490a0(param_1,uVar1 + 0x20);
    uVar2 = *(uint *)(uVar3 + 0x1c);
  }
  if ((uVar2 & 8) != 0) {
    FUN_00648cc8(param_1,uVar1 + 0x24,0x80);
    uVar2 = *(uint *)(uVar3 + 0x1c);
  }
  if ((uVar2 & 0x10) != 0) {
    FUN_00648cc8(param_1,uVar1 + 0xa4,0x80);
    FUN_006490a0(param_1,uVar1 + 0x124);
    uVar2 = *(uint *)(uVar3 + 0x1c);
  }
  if ((uVar2 & 0x20) != 0) {
    FUN_00648cc8(param_1,uVar1 + 0x128,0x100);
    uVar2 = *(uint *)(uVar3 + 0x1c);
  }
  if ((uVar2 & 0x40) != 0) {
    FUN_006490a0(param_1,uVar1 + 0x228);
    FUN_006490a0(param_1,uVar1 + 0x22c);
    FUN_006490a0(param_1,uVar1 + 0x230);
    uVar2 = *(uint *)(uVar3 + 0x1c);
  }
  if ((uVar2 & 0x80) != 0) {
    FUN_00648cc8(param_1,uVar1 + 0x234,8);
    FUN_00648cc8(param_1,uVar1 + 0x23c,0x80);
    uVar2 = *(uint *)(uVar3 + 0x1c);
  }
  if ((uVar2 & 0x100) != 0) {
    FUN_00648cc8(param_1,uVar1 + 700,0x100);
  }
  FUN_00649448(param_1,uVar1 + 0x43c);
  return;
}



// ===== function 0x675008 =====

undefined8 FUN_00675008(undefined4 param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  int iVar1;
  ulong uVar2;
  undefined1 auStack_470 [24];
  undefined4 auStack_458 [233];
  undefined1 auStack_b4 [140];
  
  uVar2 = (ulong)auStack_470 & 0xffffffff;
  func_0x006ca868(uVar2,0,0x440);
  func_0x006bfff8(uVar2,param_4 & 0xffffffff,0x440);
  if ((*(uint *)(param_4 + 0x1c) & 0x200) != 0) {
    uVar2 = (ulong)uRam0000000000e9a73c /* 'hostQuit' */;
    iVar1 = func_0x006ca940(param_4 & 0xffffffff,uVar2,0x15);
    if (iVar1 == 0) {
      func_0x006c3598(auStack_b4,uVar2 + 0x15,0x80);
    }
    else {
      auStack_458[0] = 0xfffffc3a;
    }
  }
  uVar2 = (ulong)auStack_470 & 0xffffffff;
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)uRam0000000000e9a734 /* 'endError' */ + 0x38))
            (param_1,uVar2,uVar2,auStack_458,(int)*(char *)(param_4 + 0x43c),0);
  return 0;
}



// ===== function 0x675128 =====

long FUN_00675128(void)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  int in_r6;
  ulong uVar4;
  undefined1 auStack_50 [4];
  int iStack_4c;
  int iStack_44;
  int iStack_38;
  
  uVar2 = uRam0000000000e9a73c /* 'hostQuit' */;
  uVar4 = (ulong)uRam0000000000e9a73c /* 'hostQuit' */;
  func_0x006ca868(uRam0000000000e9a73c /* 'hostQuit' */,0,0x95);
  uVar1 = (ulong)auStack_50 & 0xffffffff;
  func_0x006495f0(uVar1,in_r6,in_r6 + 0x200,2);
  FUN_00648cc8(uVar1,uVar2,0x15);
  func_0x00648f18(uVar1,uVar4 + 0x15);
  iVar3 = -1;
  if (iStack_38 == 0) {
    iVar3 = iStack_44 - iStack_4c;
  }
  return (long)iVar3;
}



