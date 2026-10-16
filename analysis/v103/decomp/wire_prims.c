// ===== function 0x6490a0 =====

undefined4 FUN_006490a0(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  if (*param_1 != -0x54324346) {
    param_1[6] = 5;
    return 0;
  }
  if (param_1[6] != 0) {
    param_1[6] = param_1[6];
    return 0;
  }
  uVar1 = param_1[3];
  if ((uint)param_1[2] <= uVar1) {
    param_1[6] = 2;
    return 0;
  }
  if (uVar1 == 0) {
    param_1[6] = 2;
    return 0;
  }
  if (param_1[2] - uVar1 < 4) {
    param_1[6] = 8;
    return 0;
  }
  if (param_1[4] == 1) {
    iVar2 = func_0x00647ef0(uVar1,(long)*param_2);
  }
  else {
    if (param_1[4] != 2) goto LAB_00649168;
    iVar2 = func_0x00647f28(uVar1,(ulong)param_2 & 0xffffffff);
  }
  if (iVar2 == 0) {
    param_1[3] = param_1[3] + 4;
    return 1;
  }
LAB_00649168:
  param_1[6] = 0;
  return 0;
}



// ===== function 0x649448 =====

undefined4 FUN_00649448(int *param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  
  if (*param_1 != -0x54324346) {
    param_1[6] = 5;
    return 0;
  }
  if (param_1[6] != 0) {
    param_1[6] = param_1[6];
    return 0;
  }
  uVar1 = param_1[3];
  if ((uint)param_1[2] <= uVar1) {
    param_1[6] = 2;
    return 0;
  }
  if (uVar1 == 0) {
    param_1[6] = 2;
    return 0;
  }
  if (param_1[4] == 1) {
    iVar2 = func_0x00647e18(uVar1,(long)*param_2);
  }
  else {
    if (param_1[4] != 2) goto LAB_00649504;
    iVar2 = func_0x00647e38(uVar1,(ulong)param_2 & 0xffffffff);
  }
  if (iVar2 == 0) {
    param_1[3] = param_1[3] + 1;
    return 1;
  }
LAB_00649504:
  param_1[6] = 0;
  return 0;
}



// ===== function 0x648cc8 =====

undefined4 FUN_00648cc8(int *param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (*param_1 == -0x54324346) {
    if (param_1[6] != 0) {
      param_1[6] = param_1[6];
      return 0;
    }
    uVar2 = param_1[3];
    if (((uVar2 < (uint)param_1[2]) && (uVar2 != 0)) && (param_2 != 0)) {
      if (param_1[2] - uVar2 < param_3) {
        uVar1 = 0;
        param_1[6] = 8;
      }
      else {
        if (param_1[4] == 1) {
          func_0x006bfff8(uVar2,param_2,param_3);
          uVar2 = param_1[3];
        }
        else if (param_1[4] == 2) {
          func_0x006bfff8(param_2,uVar2,param_3);
          uVar2 = param_1[3];
        }
        uVar1 = 1;
        param_1[3] = uVar2 + param_3;
      }
    }
    else {
      uVar1 = 0;
      param_1[6] = 2;
    }
  }
  else {
    uVar1 = 0;
    param_1[6] = 5;
  }
  return uVar1;
}



// ===== function 0x64e480 =====

void FUN_0064e480(undefined8 param_1,int *param_2)

{
  int iVar1;
  int aiStack_40 [6];
  
  iVar1 = *param_2;
  FUN_006490a0(param_1,iVar1);
  aiStack_40[0] = iVar1 + 4;
  aiStack_40[1] = 0x30;
  func_0x0064dcc8(param_1,(ulong)aiStack_40 & 0xffffffff);
  FUN_006490a0(param_1,iVar1 + 0x34);
  aiStack_40[0] = iVar1 + 0x38;
  aiStack_40[1] = 0x40;
  func_0x0064dd48(param_1,(ulong)aiStack_40 & 0xffffffff);
  FUN_00648cc8(param_1,iVar1 + 0x78,0x11);
  FUN_00648cc8(param_1,iVar1 + 0x89,0x11);
  func_0x00648e00(param_1,2);
  return;
}



// ===== function 0x64dcc8 =====

void FUN_0064dcc8(undefined8 param_1,int *param_2)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  int aiStack_30 [4];
  
  iVar1 = *param_2;
  uVar4 = 0;
  aiStack_30[1] = 0x18;
  do {
    uVar2 = uVar4 & 0xffffffff;
    uVar3 = uVar4 & 0xffffffff;
    uVar4 = uVar4 + 1;
    aiStack_30[0] = iVar1 + ((int)(uVar3 << 5) - (int)(uVar2 << 3));
    func_0x0064dca0(param_1,(ulong)aiStack_30 & 0xffffffff);
  } while (uVar4 != 2);
  return;
}



// ===== function 0x6712e8 =====

void FUN_006712e8(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  
  uVar1 = *param_2;
  piVar4 = (int *)(ulong)uVar1;
  uVar2 = param_2[1];
  FUN_006490a0(param_1,piVar4);
  iVar6 = *piVar4;
  if (iVar6 < 1) {
    if (*(int *)(param_1 + 0x10) == 2) {
      piVar4[1] = 0;
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x10);
    iStack_60 = 0;
    if (iVar3 == 2) {
      uVar7 = uVar1 + 8;
      iVar6 = iVar6 * 4 + uVar7;
      piVar4[1] = uVar7;
      *(int *)(ulong)uVar7 = iVar6;
      uVar8 = uVar7;
    }
    else {
      uVar7 = 0;
      iVar6 = piVar4[1] + iVar6 * 4;
      uVar8 = piVar4[1];
    }
    if (uVar8 <= iVar6 - 4U) {
      uVar5 = uVar8;
      while( true ) {
        uVar9 = uVar8;
        if (iVar3 == 2) {
          *(int *)(ulong)uVar9 = *(int *)(ulong)uVar5 + iStack_60;
        }
        else if (iVar3 == 1) {
          iStack_60 = func_0x00670c98(*(undefined4 *)(ulong)uVar9);
        }
        FUN_006490a0(param_1,(ulong)&iStack_60 & 0xffffffff);
        uStack_5c = *(undefined4 *)(ulong)uVar9;
        iStack_58 = iStack_60;
        func_0x006711b8(param_1,(ulong)&uStack_5c & 0xffffffff);
        uVar7 = uVar7 + 4 + iStack_60;
        if (iVar6 - 4U < uVar9 + 4) break;
        iVar3 = *(int *)(param_1 + 0x10);
        uVar8 = uVar9 + 4;
        uVar5 = uVar9;
      }
    }
    if (uVar1 + uVar2 < uVar7) {
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
  }
  return;
}



// ===== function 0x670c98 =====

long FUN_00670c98(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1 * 8 + 8;
  }
  return (long)iVar1;
}



