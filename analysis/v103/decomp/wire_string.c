// ===== function 0x648f18 =====

undefined8 FUN_00648f18(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  short sVar4;
  ushort auStack_30 [8];
  
  uVar1 = param_1[3];
  if (*param_1 != -0x54324346) {
    param_1[6] = 5;
    return 0;
  }
  iVar2 = param_1[6];
  if (iVar2 != 0) goto LAB_00648fc8;
  if (param_2 == 0) {
    param_1[6] = 2;
    return 0;
  }
  if (param_1[4] == 1) {
    sVar4 = func_0x0064ab88(param_2,0x7fff);
    auStack_30[0] = sVar4 + 1;
    if (auStack_30[0] < 0x7fff) goto LAB_00648fa8;
LAB_00649044:
    uVar3 = 0;
    param_1[6] = 9;
  }
  else {
LAB_00648fa8:
    func_0x00648b68((ulong)param_1 & 0xffffffff,auStack_30);
    iVar2 = param_1[6];
    if (iVar2 != 0) {
LAB_00648fc8:
      param_1[6] = iVar2;
      return 0;
    }
    FUN_00648cc8((ulong)param_1 & 0xffffffff,param_2,auStack_30[0]);
    if ((param_1[6] != 0) || (*(char *)((ulong)(uint)param_1[3] - 1 & 0xffffffff) != '\0')) {
      param_1[3] = uVar1;
      if (param_1[6] != 0) {
        return 0;
      }
      if (*(char *)((ulong)uVar1 - 1 & 0xffffffff) != '\0') goto LAB_00649044;
    }
    uVar3 = 1;
  }
  return uVar3;
}



