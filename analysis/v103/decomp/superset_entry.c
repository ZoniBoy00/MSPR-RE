// ===== function 0x27c5c8 =====

void FUN_0027c5c8(undefined4 *param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = uRam0000000000e99874;
  *param_1 = uRam0000000000e9983c;
  *param_1 = uVar2;
  param_1[2] = *(undefined4 *)(param_2 + 0x20);
  uVar2 = *(undefined4 *)(param_2 + 0x24);
  *(undefined1 *)((long)param_1 + 5) = 0;
  param_1[3] = uVar2;
  iVar1 = *(int *)(param_2 + 0x28);
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[4] = iVar1;
  uVar2 = *(undefined4 *)(param_2 + 0x2c);
  param_1[7] = 0;
  param_1[5] = uVar2;
  uVar2 = *(undefined4 *)(param_2 + 0x30);
  param_1[8] = 0;
  param_1[6] = uVar2;
  param_1[9] = 0;
  uVar2 = func_0x00bdf5b0(iVar1 + 1);
  param_1[7] = uVar2;
  uVar2 = func_0x00bdf5b0(param_1[5] + 1);
  param_1[8] = uVar2;
  uVar2 = func_0x00bdf5b0(param_1[6] + 1);
  puVar3 = (undefined1 *)(ulong)(uint)param_1[7];
  param_1[9] = uVar2;
  uVar2 = uRam0000000000e99878;
  puVar3[3] = 0;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3 = (undefined1 *)(ulong)(uint)param_1[8];
  puVar3[3] = 0;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3 = (undefined1 *)(ulong)(uint)param_1[9];
  puVar3[3] = 0;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  func_0x0071b5e8(param_1[7],param_1[4] + 1,uVar2,*(undefined4 *)(param_2 + 0x34));
  func_0x0071b5e8(param_1[8],param_1[5] + 1,uVar2,*(undefined4 *)(param_2 + 0x38));
  func_0x0071b5e8(param_1[9],param_1[6] + 1,uVar2,*(undefined4 *)(param_2 + 0x3c));
  *(undefined1 *)((ulong)(uint)param_1[7] + (ulong)(uint)param_1[4] & 0xffffffff) = 0;
  *(undefined1 *)((ulong)(uint)param_1[8] + (ulong)(uint)param_1[5] & 0xffffffff) = 0;
  *(undefined1 *)((ulong)(uint)param_1[9] + (ulong)(uint)param_1[6] & 0xffffffff) = 0;
  return;
}



// ===== function 0x86b400 =====

ulong FUN_0086b400(ulong param_1,ulong param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  uint *puVar12;
  undefined4 uVar13;
  char cVar14;
  uint uVar15;
  ulong uVar16;
  
  uVar15 = *(uint *)(param_1 + 0x2c);
  if (*(uint *)(param_1 + 0x30) != uVar15) {
    do {
      cVar14 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)uVar15 + 0x10))
                         ((uint *)(ulong)uVar15,param_2 & 0xffffffff);
      if (cVar14 != '\0') {
        if (*(uint *)(param_1 + 0x30) != uVar15) {
          puVar12 = (uint *)(ulong)uVar15;
          uVar1 = *(undefined1 *)((long)puVar12 + 5);
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar12 + 0x14))
                    (puVar12,param_2 & 0xffffffff);
          *(undefined1 *)((long)puVar12 + 5) = uVar1;
          *(undefined1 *)(puVar12 + 1) = 1;
          return param_1 & 0xffffffff;
        }
        break;
      }
      uVar15 = uVar15 + 0x28;
    } while (*(uint *)(param_1 + 0x30) != uVar15);
  }
  uVar16 = param_2 & 0xffffffff;
  *(undefined1 *)(param_2 + 4) = 1;
  *(undefined1 *)(param_2 + 5) = 0;
  uVar13 = uRam0000000000e99874;
  iVar3 = *(int *)(param_1 + 0x2c);
  if (iVar3 == 0) {
    uVar15 = *(uint *)(param_1 + 0x30);
  }
  else {
    uVar15 = *(uint *)(param_1 + 0x30);
    if ((uint)(((int)(uVar15 - iVar3) >> 3) * -0x33333333) <
        (uint)((*(int *)(param_1 + 0x34) - iVar3 >> 3) * -0x33333333)) {
      if (uVar15 != 0) {
        puVar11 = (undefined4 *)(ulong)uVar15;
        uVar1 = *(undefined1 *)(uVar16 + 5);
        uVar2 = *(undefined1 *)(uVar16 + 4);
        uVar4 = *(undefined4 *)(param_2 + 8);
        uVar5 = *(undefined4 *)(param_2 + 0xc);
        uVar6 = *(undefined4 *)(param_2 + 0x10);
        uVar7 = *(undefined4 *)(param_2 + 0x14);
        uVar8 = *(undefined4 *)(param_2 + 0x18);
        uVar9 = *(undefined4 *)(param_2 + 0x1c);
        uVar10 = *(undefined4 *)(param_2 + 0x20);
        puVar11[9] = *(undefined4 *)(param_2 + 0x24);
        *(undefined1 *)(puVar11 + 1) = uVar2;
        *(undefined1 *)((long)puVar11 + 5) = uVar1;
        *puVar11 = uVar13;
        puVar11[2] = uVar4;
        puVar11[3] = uVar5;
        puVar11[4] = uVar6;
        puVar11[5] = uVar7;
        puVar11[6] = uVar8;
        puVar11[7] = uVar9;
        puVar11[8] = uVar10;
      }
      *(uint *)(param_1 + 0x30) = uVar15 + 0x28;
      return param_1 & 0xffffffff;
    }
  }
  func_0x0086a628(param_1 + 0x28 & 0xffffffff,uVar15,1,uVar16);
  return param_1 & 0xffffffff;
}



// ===== function 0x26d4a8 =====

void FUN_0026d4a8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = uRam0000000000e994a8;
  *param_1 = uRam0000000000e993c8;
  *param_1 = uVar1;
  param_1[2] = 3;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((long)param_1 + 5) = 0;
  param_1[3] = 4;
  *(undefined1 *)(param_1 + 4) = 0;
  func_0x0071b038((ulong)param_1 & 0xffffffff,0,0xdc);
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[2] = 3;
  param_1[3] = 4;
  param_1[0x32] = param_3;
  param_1[0x10] = param_2;
  param_1[0x2b] = param_4;
  param_1[0x2a] = 2;
  return;
}



