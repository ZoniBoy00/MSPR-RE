// ===== function 0x648b68 =====

undefined8 FUN_00648b68(int *param_1,ushort *param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined8 uVar3;
  uint uVar4;
  
  if (*param_1 != -0x54324346) {
    param_1[6] = 5;
    return 0;
  }
  if (param_1[6] != 0) {
    param_1[6] = param_1[6];
    return 0;
  }
  uVar4 = param_1[3];
  if ((uVar4 < (uint)param_1[2]) && (uVar4 != 0)) {
    if (param_1[2] - uVar4 < 2) {
      param_1[6] = 8;
      return 0;
    }
    if (param_1[4] == 1) {
      uVar2 = *param_2;
      if (0x7ffe < uVar2) goto LAB_00648bf8;
      if (0x7f < uVar2) {
        *(byte *)(ulong)uVar4 = (byte)(uVar2 >> 8) | 0x80;
        uVar2 = *param_2;
        uVar4 = param_1[3] + 1;
        param_1[3] = uVar4;
      }
      *(char *)(ulong)uVar4 = (char)uVar2;
      uVar4 = param_1[3];
    }
    else if (param_1[4] == 2) {
      bVar1 = *(byte *)(ulong)uVar4;
      *param_2 = (ushort)bVar1;
      if ((bVar1 & 0x80) != 0) {
        uVar2 = (bVar1 & 0x7f) << 8;
        *param_2 = uVar2;
        param_1[3] = uVar4 + 1;
        *param_2 = uVar2 | *(byte *)(ulong)(uVar4 + 1);
      }
      if (0x7ffe < *param_2) {
        param_1[6] = 2;
        return 0;
      }
      uVar4 = param_1[3];
    }
    uVar3 = 1;
    param_1[3] = uVar4 + 1;
  }
  else {
LAB_00648bf8:
    uVar3 = 0;
    param_1[6] = 2;
  }
  return uVar3;
}



