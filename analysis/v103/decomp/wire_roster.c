// ===== function 0x6711b8 =====

void FUN_006711b8(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = *param_2;
  piVar3 = (int *)(ulong)uVar1;
  uVar2 = param_2[1];
  FUN_006490a0(param_1,piVar3);
  if (*piVar3 < 1) {
    uVar5 = 4;
    if (*(int *)(param_1 + 0x10) == 2) {
      piVar3[1] = 0;
    }
  }
  else {
    iVar6 = 4;
    if (*(int *)(param_1 + 0x10) == 2) {
      iVar6 = uVar1 + 8;
      piVar3[1] = iVar6;
    }
    iVar7 = 0;
    do {
      FUN_006490a0(param_1,iVar7 * 8 + piVar3[1] + 4);
      FUN_006490a0(param_1,iVar7 * 8 + piVar3[1]);
      iVar4 = iVar7 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar4 < *piVar3);
    uVar5 = iVar6 + iVar7 * 8;
  }
  if (uVar1 + uVar2 < uVar5) {
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  return;
}



// ===== function 0x64dca0 =====

void FUN_0064dca0(void)

{
  func_0x0064e560();
  return;
}



