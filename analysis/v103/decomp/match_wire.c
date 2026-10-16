// ===== function 0x673128 =====

undefined8 FUN_00673128(undefined8 param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)uRam0000000000e9a734 /* 'endError' */ + 0x38))
            (param_1,param_4 & 0xffffffff,param_4 & 0xffffffff,param_4 + 0x18 & 0xffffffff,
             (int)*(char *)(param_4 + 0x1c),0);
  return 0x40;
}



// ===== function 0x6728e0 =====

void FUN_006728e0(long param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = *param_2;
  uVar5 = (ulong)uVar2;
  uVar3 = param_2[1];
  func_0x00648cc8(param_1,uVar5,0x15);
  func_0x006490a0(param_1,uVar2 + 0x18);
  func_0x00649448(param_1,uVar2 + 0x1c);
  func_0x006490a0(param_1,uVar2 + 0x18);
  func_0x006490a0(param_1,uVar2 + 0x20);
  func_0x006490a0(param_1,uVar2 + 0x24);
  func_0x006490a0(param_1,uVar2 + 0x28);
  func_0x006490a0(param_1,uVar2 + 0x2c);
  func_0x006490a0(param_1,uVar2 + 0x30);
  iVar6 = *(int *)(param_1 + 0x10);
  bVar1 = iVar6 == 2;
  if (bVar1) {
    uVar8 = uVar2 + 0x40;
  }
  else {
    uVar8 = 0;
  }
  iVar4 = *(int *)(uVar5 + 0x28);
  if (iVar4 == 0) {
    if (bVar1) {
      *(undefined4 *)(uVar5 + 0x34) = 0;
    }
  }
  else {
    if (bVar1) {
      *(uint *)(uVar5 + 0x34) = uVar8;
      func_0x00648cc8(param_1,*(undefined4 *)(uVar5 + 0x34),iVar4);
      iVar6 = *(int *)(param_1 + 0x10);
    }
    else {
      func_0x00648cc8(param_1,*(undefined4 *)(uVar5 + 0x34),iVar4);
      iVar6 = *(int *)(param_1 + 0x10);
    }
    if (iVar6 == 2) {
      uVar7 = uVar8 + *(int *)(uVar5 + 0x28);
      uVar8 = uVar7 + 1;
      *(undefined1 *)(ulong)uVar7 = 0;
      iVar6 = *(int *)(param_1 + 0x10);
    }
  }
  iVar4 = *(int *)(uVar5 + 0x2c);
  if (iVar4 == 0) {
    if (iVar6 == 2) {
      *(undefined4 *)(uVar5 + 0x38) = 0;
    }
  }
  else {
    if (iVar6 == 2) {
      *(uint *)(uVar5 + 0x38) = uVar8;
      func_0x00648cc8(param_1,*(undefined4 *)(uVar5 + 0x38),iVar4);
      iVar6 = *(int *)(param_1 + 0x10);
    }
    else {
      func_0x00648cc8(param_1,*(undefined4 *)(uVar5 + 0x38),iVar4);
      iVar6 = *(int *)(param_1 + 0x10);
    }
    if (iVar6 == 2) {
      uVar8 = uVar8 + *(int *)(uVar5 + 0x2c);
      *(undefined1 *)(ulong)uVar8 = 0;
      iVar6 = *(int *)(param_1 + 0x10);
    }
  }
  iVar4 = *(int *)(uVar5 + 0x30);
  if (iVar4 == 0) {
    if (iVar6 == 2) {
      *(undefined4 *)(uVar5 + 0x3c) = 0;
    }
  }
  else {
    if (iVar6 == 2) {
      *(uint *)(uVar5 + 0x3c) = uVar8;
      func_0x00648cc8(param_1,*(undefined4 *)(uVar5 + 0x3c),iVar4);
      iVar6 = *(int *)(param_1 + 0x10);
    }
    else {
      func_0x00648cc8(param_1,*(undefined4 *)(uVar5 + 0x3c),iVar4);
      iVar6 = *(int *)(param_1 + 0x10);
    }
    if (iVar6 == 2) {
      uVar8 = uVar8 + *(int *)(uVar5 + 0x30);
      *(undefined1 *)(ulong)uVar8 = 0;
    }
  }
  if (uVar2 + uVar3 < uVar8) {
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  return;
}



// ===== function 0x6714a8 =====

void FUN_006714a8(long param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  uVar2 = *param_2;
  uVar4 = (ulong)uVar2;
  uVar3 = param_2[1];
  func_0x00648cc8(param_1,uVar4,0x15);
  func_0x00648cc8(param_1,uVar2 + 0x15,0x11);
  func_0x006490a0(param_1,uVar2 + 0x28);
  func_0x006490a0(param_1,uVar2 + 0x2c);
  func_0x006490a0(param_1,uVar2 + 0x30);
  func_0x006490a0(param_1,uVar2 + 0x34);
  func_0x006490a0(param_1,uVar2 + 0x38);
  func_0x006490a0(param_1,uVar2 + 0x3c);
  iVar6 = *(int *)(param_1 + 0x10);
  bVar1 = iVar6 == 2;
  if (bVar1) {
    uVar7 = uVar2 + 0x48;
  }
  else {
    uVar7 = 0;
  }
  if (*(int *)(uVar4 + 0x2c) == 0) {
    if (bVar1) {
      *(undefined4 *)(uVar4 + 0x40) = 0;
    }
  }
  else {
    if (bVar1) {
      *(uint *)(uVar4 + 0x40) = uVar7;
    }
    iVar8 = 0;
    do {
      func_0x006490a0(param_1,iVar8 * 4 + *(int *)(uVar4 + 0x40));
      uVar5 = iVar8 + 1;
      iVar8 = iVar8 + 1;
    } while (uVar5 < *(uint *)(uVar4 + 0x2c));
    iVar6 = *(int *)(param_1 + 0x10);
    uVar7 = uVar7 + iVar8 * 4;
  }
  iVar8 = *(int *)(uVar4 + 0x3c);
  if (iVar8 == 0) {
    if (iVar6 == 2) {
      *(undefined4 *)(uVar4 + 0x44) = 0;
    }
  }
  else {
    if (iVar6 == 2) {
      *(uint *)(uVar4 + 0x44) = uVar7;
      func_0x00648cc8(param_1,*(undefined4 *)(uVar4 + 0x44),iVar8);
      iVar6 = *(int *)(param_1 + 0x10);
    }
    else {
      func_0x00648cc8(param_1,*(undefined4 *)(uVar4 + 0x44),iVar8);
      iVar6 = *(int *)(param_1 + 0x10);
    }
    if (iVar6 == 2) {
      uVar7 = uVar7 + *(int *)(uVar4 + 0x3c);
    }
  }
  if (uVar2 + uVar3 < uVar7) {
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  return;
}



// ===== function 0x673190 =====

undefined8 FUN_00673190(undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)uRam0000000000e9a734 /* 'endError' */ + 0x38))
            (param_1,param_4,param_4,param_4 + 0x18,1,0);
  return 0xc0;
}



// ===== function 0x6720e0 =====

void FUN_006720e0(long param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  
  uVar2 = *param_2;
  uVar4 = (ulong)uVar2;
  uVar3 = param_2[1];
  func_0x00648cc8(param_1,uVar4,0x15);
  func_0x006490a0(param_1,uVar2 + 0x18);
  func_0x006490a0(param_1,uVar2 + 0x1c);
  iVar5 = *(int *)(uVar4 + 0x18);
  if (iVar5 != 6) {
    if (iVar5 == 7) {
      iVar5 = 0;
      func_0x006490a0(param_1,uVar2 + 0x20);
      func_0x006490a0(param_1,uVar2 + 0x24);
      if (*(int *)(param_1 + 0x10) == 2) {
        iVar5 = uVar2 + 0xc0;
        *(int *)(uVar4 + 0x28) = iVar5;
      }
      func_0x00648cc8(param_1,*(undefined4 *)(uVar4 + 0x28),*(undefined4 *)(uVar4 + 0x24));
      uVar9 = iVar5 + *(int *)(uVar4 + 0x24);
    }
    else {
      if (iVar5 != 8) {
        return;
      }
      func_0x006490a0(param_1,uVar2 + 0x20);
      iStack_5c = uVar2 + 0x24;
      iStack_58 = 0x9c;
      func_0x0064e480(param_1,&iStack_5c);
      if (*(int *)(param_1 + 0x10) != 2) {
        return;
      }
      uVar9 = uVar2 + 0xc0;
    }
    goto LAB_00672200;
  }
  iStack_60 = 0;
  func_0x006490a0(param_1,uVar2 + 0x20);
  func_0x00648cc8(param_1,uVar2 + 0x24,0x20);
  func_0x006490a0(param_1,uVar2 + 0x44);
  iStack_5c = uVar2 + 0x48;
  iStack_58 = 0x30;
  func_0x0064dcc8(param_1,&iStack_5c);
  func_0x006490a0(param_1,uVar2 + 0x78);
  iVar5 = *(int *)(param_1 + 0x10);
  bVar1 = iVar5 == 2;
  if (bVar1) {
    iVar8 = uVar2 + 0xc0;
  }
  else {
    iVar8 = 0;
  }
  if (*(int *)(uVar4 + 0x78) == 0) {
    if (bVar1) {
      *(undefined4 *)(uVar4 + 0x7c) = 0;
      iVar5 = *(int *)(param_1 + 0x10);
    }
LAB_00672310:
    iVar7 = iStack_60;
    if (iVar5 == 1) {
      uVar9 = *(uint *)(uVar4 + 0x80);
      if (uVar9 == 0) {
        iStack_60 = 0;
        iVar7 = iStack_60;
      }
      else {
        uVar10 = ((int *)(ulong)uVar9)[1];
        iVar7 = *(int *)(ulong)uVar9 * 4;
        iVar5 = uVar10 + iVar7;
        iVar7 = iVar7 + 8;
        for (; uVar10 <= iVar5 - 4U; uVar10 = uVar10 + 4) {
          iVar6 = func_0x00670c98(*(undefined4 *)(ulong)uVar10);
          iVar7 = iVar7 + iVar6;
        }
      }
    }
  }
  else {
    if (bVar1) {
      *(int *)(uVar4 + 0x7c) = iVar8;
    }
    func_0x00648cc8(param_1,*(undefined4 *)(uVar4 + 0x7c),*(int *)(uVar4 + 0x78));
    iVar5 = *(int *)(param_1 + 0x10);
    if (iVar5 != 2) goto LAB_00672310;
    iVar8 = iVar8 + *(int *)(uVar4 + 0x78);
    iVar7 = iStack_60;
  }
  iStack_60 = iVar7;
  uVar9 = iVar8 + 4;
  func_0x006490a0(param_1,&iStack_60);
  if (iStack_60 < 1) {
    if (*(int *)(param_1 + 0x10) == 2) {
      *(undefined4 *)(uVar4 + 0x80) = 0;
    }
  }
  else {
    if (*(int *)(param_1 + 0x10) == 2) {
      *(uint *)(uVar4 + 0x80) = uVar9;
    }
    iStack_58 = iStack_60;
    iStack_5c = *(int *)(uVar4 + 0x80);
    func_0x006712e8(param_1,&iStack_5c);
    uVar9 = uVar9 + iStack_60;
  }
LAB_00672200:
  if (uVar9 <= uVar2 + uVar3) {
    return;
  }
  *(undefined4 *)(param_1 + 0x18) = 1;
  return;
}



// ===== function 0x670cb8 =====

void FUN_00670cb8(undefined8 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  func_0x00648cc8(param_1,iVar1,0x15);
  func_0x00648cc8(param_1,iVar1 + 0x15,0x11);
  return;
}



