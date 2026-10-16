// ===== function 0x2801d8 =====

void FUN_002801d8(long param_1,long param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  uint *puVar10;
  char cVar12;
  int *piVar11;
  uint uVar15;
  ulong uVar13;
  uint *puVar14;
  int iVar16;
  uint *puVar17;
  int iVar19;
  ulong uVar18;
  ulong uVar21;
  ulong uVar22;
  ulong uVar23;
  ulong uVar24;
  int *piVar25;
  undefined4 auStack_110 [58];
  int iVar20;
  
  if (((*(uint *)(ulong)uRam0000000000e997e0 == 0) ||
      (piVar3 = (int *)(ulong)*(uint *)(ulong)uRam0000000000e997e0,
      piVar3[3] != *(int *)(param_4 + 0x24))) || ((piVar3[1] == 3 && (*piVar3 == 0x5b)))) {
    func_0x0027c1b8(uRam0000000000e9982c,(long)*(int *)(param_4 + 0x24));
    return;
  }
  func_0x0027c1b8(uRam0000000000e99a2c);
  uVar6 = uRam0000000000e99a28;
  iVar1 = *(int *)(param_4 + 0x1c);
  if (iVar1 == 8) {
    func_0x0027c1b8(uRam0000000000e99a14);
    func_0x0071b098(param_1 + 0x298U & 0xffffffff,param_2 + 0x24U & 0xffffffff,0x9c);
    func_0x002c1ac0(piVar3,uRam0000000000e99a18);
    return;
  }
  if (iVar1 != 6) {
    if (iVar1 == 1) {
      puVar10 = (uint *)(ulong)uRam0000000000e997d4;
      *(undefined4 *)(param_1 + 0x68c) = 0xffffffff;
      cVar12 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar10 + 0x2ac))
                         ((uint *)(ulong)*puVar10);
      if (cVar12 == '\0') {
        func_0x002c1d28(piVar3,0x2f,uRam0000000000e99a24);
        return;
      }
      func_0x002c1ac0(piVar3,uRam0000000000e99a24);
      return;
    }
    if (-1 < iVar1) {
      return;
    }
    *(undefined4 *)(param_1 + 0x68c) = 0xffffffff;
    func_0x002c1d28(piVar3,0x2e,uVar6,(long)iVar1);
    return;
  }
  iVar16 = 0;
  iVar1 = *(int *)(ulong)*(uint *)(param_2 + 0x80);
  if (0 < iVar1) {
    uVar2 = ((int *)(ulong)*(uint *)(param_2 + 0x80))[1];
    uVar15 = iVar1 - 1;
    uVar21 = (ulong)uVar2 + 4;
    uVar4 = uVar15 & 7;
    iVar20 = 1;
    iVar19 = 1;
    iVar16 = *(int *)(ulong)*(uint *)(ulong)uVar2;
    if (iVar1 != 1) {
      if ((uVar15 & 7) != 0) {
        if (uVar4 != 1) {
          if (uVar4 != 2) {
            if (uVar4 != 3) {
              if (uVar4 != 4) {
                if (uVar4 != 5) {
                  if (uVar4 != 6) {
                    puVar10 = (uint *)(uVar21 & 0xffffffff);
                    iVar20 = 2;
                    uVar21 = (ulong)uVar2 + 8;
                    iVar16 = iVar16 + *(int *)(ulong)*puVar10;
                  }
                  puVar10 = (uint *)(uVar21 & 0xffffffff);
                  iVar20 = iVar20 + 1;
                  uVar21 = uVar21 + 4;
                  iVar16 = iVar16 + *(int *)(ulong)*puVar10;
                }
                puVar10 = (uint *)(uVar21 & 0xffffffff);
                iVar20 = iVar20 + 1;
                uVar21 = uVar21 + 4;
                iVar16 = iVar16 + *(int *)(ulong)*puVar10;
              }
              puVar10 = (uint *)(uVar21 & 0xffffffff);
              iVar20 = iVar20 + 1;
              uVar21 = uVar21 + 4;
              iVar16 = iVar16 + *(int *)(ulong)*puVar10;
            }
            puVar10 = (uint *)(uVar21 & 0xffffffff);
            iVar20 = iVar20 + 1;
            uVar21 = uVar21 + 4;
            iVar16 = iVar16 + *(int *)(ulong)*puVar10;
          }
          puVar10 = (uint *)(uVar21 & 0xffffffff);
          iVar19 = iVar20 + 1;
          uVar21 = uVar21 + 4;
          iVar16 = iVar16 + *(int *)(ulong)*puVar10;
        }
        puVar10 = (uint *)(uVar21 & 0xffffffff);
        uVar21 = uVar21 + 4;
        iVar16 = iVar16 + *(int *)(ulong)*puVar10;
        if (iVar1 == iVar19 + 1) goto LAB_002804b4;
      }
      uVar7 = (ulong)(uVar15 >> 3) - 1 & 0xffffffff;
      uVar13 = uVar7 + 1;
      if (uVar13 < 3) {
        do {
          uVar9 = uVar21 + 4;
          puVar10 = (uint *)(uVar21 & 0xffffffff);
          uVar23 = uVar21 + 8;
          uVar22 = uVar21 + 0xc;
          uVar7 = uVar21 + 0x10;
          uVar18 = uVar21 + 0x14;
          uVar24 = uVar21 + 0x18;
          uVar8 = uVar21 + 0x1c;
          uVar21 = uVar21 + 0x20;
          iVar16 = iVar16 + *(int *)(ulong)*puVar10 + *(int *)(ulong)*(uint *)(uVar9 & 0xffffffff) +
                   *(int *)(ulong)*(uint *)(uVar23 & 0xffffffff) +
                   *(int *)(ulong)*(uint *)(uVar22 & 0xffffffff) +
                   *(int *)(ulong)*(uint *)(uVar7 & 0xffffffff) +
                   *(int *)(ulong)*(uint *)(uVar18 & 0xffffffff) +
                   *(int *)(ulong)*(uint *)(uVar24 & 0xffffffff) +
                   *(int *)(ulong)*(uint *)(uVar8 & 0xffffffff);
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      else {
        piVar11 = (int *)(ulong)*(uint *)(uVar21 + 4 & 0xffffffff);
        puVar10 = (uint *)(uVar21 + 0xc & 0xffffffff);
        uVar13 = uVar21 + 0x18;
        piVar25 = (int *)(ulong)*(uint *)(uVar21 + 8 & 0xffffffff);
        iVar16 = iVar16 + *(int *)(ulong)*(uint *)(uVar21 & 0xffffffff);
        puVar14 = (uint *)(uVar21 + 0x10 & 0xffffffff);
        puVar17 = (uint *)(uVar21 + 0x14 & 0xffffffff);
        do {
          uVar8 = uVar21;
          iVar16 = iVar16 + *piVar11 + *piVar25 + *(int *)(ulong)*puVar10 + *(int *)(ulong)*puVar14
                   + *(int *)(ulong)*puVar17 + *(int *)(ulong)*(uint *)(uVar13 & 0xffffffff) +
                   *(int *)(ulong)*(uint *)(uVar8 + 0x1c & 0xffffffff) +
                   *(int *)(ulong)*(uint *)(uVar8 + 0x20 & 0xffffffff);
          puVar10 = (uint *)(uVar8 + 0x2c & 0xffffffff);
          piVar11 = (int *)(ulong)*(uint *)(uVar8 + 0x24 & 0xffffffff);
          puVar14 = (uint *)(uVar8 + 0x30 & 0xffffffff);
          piVar25 = (int *)(ulong)*(uint *)(uVar8 + 0x28 & 0xffffffff);
          puVar17 = (uint *)(uVar8 + 0x34 & 0xffffffff);
          uVar13 = uVar8 + 0x38;
          uVar7 = uVar7 - 1;
          uVar21 = uVar8 + 0x20;
        } while (uVar7 != 0);
        iVar16 = iVar16 + *piVar11 + *piVar25 + *(int *)(ulong)*puVar10 + *(int *)(ulong)*puVar14 +
                 *(int *)(ulong)*puVar17 + *(int *)(ulong)*(uint *)(uVar13 & 0xffffffff) +
                 *(int *)(ulong)*(uint *)(uVar8 + 0x3c & 0xffffffff);
      }
    }
  }
LAB_002804b4:
  puVar5 = (undefined4 *)((ulong)auStack_110 & 0xffffffff);
  func_0x0026d4a8(puVar5,(long)*(int *)(param_2 + 0x20),5,(long)iVar16);
  func_0x0071b098(param_1 + 0x64cU & 0xffffffff,puVar5,0xdc);
  uVar6 = uRam0000000000e99a20;
  auStack_110[0] = uRam0000000000e99a1c;
  *puVar5 = uRam0000000000e9983c;
  func_0x002c1ac0(piVar3,uVar6);
  return;
}



// ===== function 0x281ea0 =====

void FUN_00281ea0(long param_1,ulong param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  int *piVar6;
  uint uVar7;
  ulong uVar8;
  undefined4 uVar9;
  uint *puVar10;
  ulong uVar11;
  ulong uVar12;
  undefined4 uStack_90;
  undefined1 uStack_8c;
  undefined1 uStack_8b;
  undefined4 uStack_88;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 auStack_68 [10];
  
  if (((*(uint *)(ulong)uRam0000000000e997e0 == 0) ||
      (piVar6 = (int *)(ulong)*(uint *)(ulong)uRam0000000000e997e0,
      piVar6[3] != *(int *)(param_4 + 0x24))) || ((piVar6[1] == 3 && (*piVar6 == 0x5b)))) {
    func_0x0027c1b8(uRam0000000000e9982c,(long)*(int *)(param_4 + 0x24));
    return;
  }
  if (*(int *)(param_4 + 0x1c) == 0) {
    func_0x0027c5c8((ulong)auStack_68 & 0xffffffff,param_2 & 0xffffffff);
    func_0x0086b400(*(undefined4 *)(param_1 + 0x808),(ulong)auStack_68 & 0xffffffff);
    auStack_68[0] = uRam0000000000e9983c;
    func_0x0027c1b8(uRam0000000000e99a80,*(undefined4 *)(param_2 + 0x34));
    func_0x002c1b68(piVar6,(long)*(char *)(param_2 + 0x1c),uRam0000000000e99a84);
LAB_002822fc:
    iVar1 = piVar6[1];
  }
  else {
    if (*(int *)(param_4 + 0x1c) == 1) {
      func_0x002c1d28(piVar6,0x2d,uRam0000000000e99a88);
      goto LAB_002822fc;
    }
    func_0x002c1d28(piVar6,0x2d,uRam0000000000e99a8c);
    iVar1 = piVar6[1];
  }
  if (iVar1 != 4) {
    func_0x0027c1b8(uRam0000000000e99a90);
    func_0x0086ebe0(*(undefined4 *)(param_1 + 0x808));
  }
  uVar9 = uRam0000000000e99874;
  if (*(int *)(param_4 + 0x1c) == 0) {
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x808);
  if (uVar2 == 0) goto LAB_00282408;
  uVar8 = (ulong)uVar2 + 0x28 & 0xffffffff;
  uStack_90 = uRam0000000000e99874;
  uStack_8b = 0;
  uVar3 = *(uint *)(uVar8 + 4);
  uVar11 = (ulong)uVar3;
  uStack_6c = 0;
  uStack_88 = 0xffffffff;
  uStack_8c = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  if (uVar3 != 0) {
    uVar4 = *(uint *)(uVar8 + 8);
    if ((0x4e < ((uVar4 - uVar11) + 0x27 & 0xffffffff)) && (uVar3 != uVar4)) {
      uVar5 = (uVar4 - uVar11) - 0x28 >> 3;
      uVar7 = (uint)uVar5 & 3;
      (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(ulong)uVar3)((uint *)(ulong)uVar3);
      uVar12 = uVar11 + 0x28;
      if ((uint)uVar12 != uVar4) {
        if ((uVar5 & 3) != 0) {
          if (uVar7 != 1) {
            if (uVar7 != 2) {
              (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(uVar12 & 0xffffffff))
                        ((uint *)(uVar12 & 0xffffffff));
              uVar12 = uVar11 + 0x50;
            }
            (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(uVar12 & 0xffffffff))
                      ((uint *)(uVar12 & 0xffffffff));
            uVar12 = uVar12 + 0x28;
          }
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(uVar12 & 0xffffffff))
                    ((uint *)(uVar12 & 0xffffffff));
          uVar12 = uVar12 + 0x28;
          if ((uint)uVar12 == uVar4) goto LAB_00282190;
        }
        do {
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(uVar12 & 0xffffffff))
                    ((uint *)(uVar12 & 0xffffffff));
          puVar10 = (uint *)(uVar12 + 0x28 & 0xffffffff);
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*puVar10)(puVar10);
          puVar10 = (uint *)(uVar12 + 0x50 & 0xffffffff);
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*puVar10)(puVar10);
          puVar10 = (uint *)(uVar12 + 0x78 & 0xffffffff);
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*puVar10)(puVar10);
          uVar12 = uVar12 + 0xa0;
        } while ((uint)uVar12 != uVar4);
      }
LAB_00282190:
      *(uint *)(uVar8 + 8) = uVar3;
    }
  }
  uStack_90 = uVar9;
  *(undefined4 *)((ulong)&uStack_90 & 0xffffffff) = uRam0000000000e9983c;
  uVar3 = *(uint *)(uVar8 + 4);
  uVar11 = (ulong)uVar3;
  if (uVar3 != 0) {
    uVar4 = *(uint *)(uVar8 + 8);
    if (uVar3 != uVar4) {
      uVar12 = uVar11 + 0x28;
      uVar5 = (uVar4 - uVar11) - 0x28 >> 3;
      uVar7 = (uint)uVar5 & 3;
      (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(ulong)uVar3)((uint *)(ulong)uVar3);
      if (uVar4 != (uint)uVar12) {
        if ((uVar5 & 3) == 0) goto LAB_00282328;
        if (uVar7 != 1) {
          if (uVar7 != 2) {
            puVar10 = (uint *)(uVar12 & 0xffffffff);
            uVar12 = uVar11 + 0x50;
            (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*puVar10)(puVar10);
          }
          puVar10 = (uint *)(uVar12 & 0xffffffff);
          uVar12 = uVar12 + 0x28;
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*puVar10)(puVar10);
        }
        puVar10 = (uint *)(uVar12 & 0xffffffff);
        uVar3 = *(uint *)(ulong)*puVar10;
        for (uVar12 = uVar12 + 0x28; (*(code *)(ulong)*(uint *)(ulong)uVar3)(puVar10),
            uVar4 != (uint)uVar12; uVar12 = uVar12 + 0xa0) {
LAB_00282328:
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(uVar12 & 0xffffffff))
                    ((uint *)(uVar12 & 0xffffffff));
          puVar10 = (uint *)(uVar12 + 0x28 & 0xffffffff);
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*puVar10)(puVar10);
          puVar10 = (uint *)(uVar12 + 0x50 & 0xffffffff);
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*puVar10)(puVar10);
          puVar10 = (uint *)(uVar12 + 0x78 & 0xffffffff);
          uVar3 = *(uint *)(ulong)*puVar10;
        }
      }
    }
    func_0x0071b0c8(*(undefined4 *)(uVar8 + 4));
  }
  *(undefined4 *)(uVar8 + 0xc) = 0;
  *(undefined4 *)(uVar8 + 4) = 0;
  *(undefined4 *)(uVar8 + 8) = 0;
  func_0x0071b0c8(uVar2);
LAB_00282408:
  *(undefined4 *)(param_1 + 0x808) = 0;
  return;
}



// ===== function 0x27d9e8 =====

void FUN_0027d9e8(long param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int iVar7;
  int iVar8;
  char cVar13;
  int iVar9;
  undefined4 uVar10;
  undefined1 *puVar6;
  uint uVar11;
  int iVar12;
  ulong uVar14;
  uint *puVar15;
  int iVar16;
  long lVar17;
  uint uVar18;
  uint *puVar19;
  undefined8 uStack_100;
  undefined1 auStack_f4 [48];
  undefined1 auStack_c4 [21];
  undefined1 auStack_af [19];
  int iStack_9c;
  int iStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  int iStack_80;
  
  func_0x0027c1b8(uRam0000000000e998e8);
  puVar15 = (uint *)(ulong)uRam0000000000e997d4;
  iVar7 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar15 + 0xc2c))
                    ((uint *)(ulong)*puVar15);
  func_0x0027c1b8(uRam0000000000e998ec,(long)iVar7);
  puVar19 = (uint *)(ulong)uRam0000000000e997e0;
  uVar14 = (ulong)*puVar19;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(uVar14 + 0xc);
  func_0x002c1880(uVar14,0);
  uVar2 = *puVar19;
  uVar18 = *(uint *)((ulong)*(uint *)(param_1 + 0x808) + 0x30);
  uVar11 = *(uint *)((ulong)*(uint *)(param_1 + 0x808) + 0x2c);
  if (uVar11 < uVar18) {
    do {
      iVar7 = *(int *)((ulong)uVar11 + 8);
      if (iVar7 == *(int *)(param_1 + 0x834)) {
        if (iVar7 < 0) {
          return;
        }
        goto LAB_0027db04;
      }
      uVar11 = uVar11 + 0x28;
    } while (uVar11 < uVar18);
  }
  iVar7 = 0;
  func_0x002c1d28(uVar2,0x2e,uRam0000000000e99824);
LAB_0027db04:
  puVar3 = (undefined4 *)((ulong)auStack_f4 & 0xffffffff);
  iVar8 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar15 + 0xa40))
                    ((uint *)(ulong)*puVar15);
  puVar3[0xb] = 0;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 0;
  puVar3[8] = 0;
  puVar3[9] = 0;
  puVar3[10] = 0;
  func_0x0071b038(auStack_c4,0,0x48);
  cVar13 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar15 + 0x1a0))
                     ((uint *)(ulong)*puVar15);
  if (cVar13 == '\0') {
    iVar12 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar15 + 0xc2c))
                       ((uint *)(ulong)*puVar15);
  }
  else {
    iVar12 = -1;
  }
  bVar1 = *(byte *)(param_1 + 0x838);
  iVar16 = 0;
  puVar19 = (uint *)(ulong)uRam0000000000e997d4;
  lVar17 = 0;
  uStack_100 = (ulong)bVar1 << 0x38;
  uVar18 = 0;
  while( true ) {
    uVar11 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar15 + 0xa40))
                       ((uint *)(ulong)*puVar15);
    if (uVar11 <= uVar18) break;
    iVar9 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar19 + 0xa44))
                      ((uint *)(ulong)*puVar19,uVar18);
    if (iVar9 < 0) {
      func_0x002c1d28(uVar2,0x2e,uRam0000000000e998f0);
      return;
    }
    iVar9 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar19 + 0xa4c))
                      ((uint *)(ulong)*puVar19,uVar18);
    iVar16 = iVar16 + iVar9;
    uVar10 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar19 + 0xa44))
                       ((uint *)(ulong)*puVar19,uVar18);
    uVar11 = *puVar19;
    puVar6 = auStack_f4 + lVar17;
    lVar17 = lVar17 + 4;
    *(undefined4 *)((ulong)puVar6 & 0xffffffff) = uVar10;
    iVar9 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)uVar11 + 0xa4c))
                      ((uint *)(ulong)uVar11,uVar18);
    func_0x0027c1b8(uRam0000000000e998f4,uVar18,uVar10,(long)iVar9);
    uVar18 = uVar18 + 1;
  }
  if (bVar1 == 0) {
    uVar10 = 4;
  }
  else {
    if ((0 < iVar8) && (0 < iVar16)) {
      uVar10 = 6;
      uStack_100 = CONCAT44(uStack_100._0_4_,iVar16 / iVar8);
      cVar13 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar15 + 0x2ac))
                         ((uint *)(ulong)*puVar15);
      uVar4 = uStack_100;
      goto joined_r0x0027df48;
    }
    uVar10 = 6;
  }
  uStack_100 = CONCAT44(uStack_100._0_4_,1);
  cVar13 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar15 + 0x2ac))
                     ((uint *)(ulong)*puVar15);
  uVar4 = uStack_100;
joined_r0x0027df48:
  if (cVar13 != '\0') {
    func_0x0027c1b8(uRam0000000000e998f8);
  }
  func_0x0027c1b8(uRam0000000000e998fc);
  func_0x0027c1b8(uRam0000000000e99900);
  uStack_100._0_1_ = (undefined1)((ulong)uVar4 >> 0x38);
  func_0x0027c1b8(uRam0000000000e99904,uStack_100._0_1_);
  uStack_100._4_4_ = (int)uVar4;
  func_0x0027c1b8(uRam0000000000e99908,(long)uStack_100._4_4_);
  func_0x0027c1b8(uRam0000000000e9990c,(long)iVar12);
  func_0x0027c1b8(uRam0000000000e99910);
  func_0x0027c1b8(uRam0000000000e99914,(long)iVar8);
  func_0x0027c1b8(uRam0000000000e99918,uVar10);
  func_0x0027c1b8(uRam0000000000e9991c,(long)iVar7);
  func_0x0027c1b8(uRam0000000000e99920);
  func_0x0071b048(auStack_af,param_1 + 0x78U & 0xffffffff);
  uVar5 = uRam0000000000e99924;
  *(undefined4 *)(param_1 + 0x1c) = 120000;
  uStack_8c = 2;
  uStack_84 = SUB84(auStack_f4,0);
  uStack_88 = 0xc;
  uStack_90 = 0xc;
  iStack_9c = iVar7;
  iStack_98 = iVar8;
  uStack_94 = uVar10;
  iStack_80 = (int)&stack0xfffffffffffffe90 + 0x70;
  iVar7 = func_0x0071d568(auStack_c4,uVar5,param_1 + 8U & 0xffffffff);
  *(int *)(param_1 + 0x334) = iVar7;
  if (iVar7 != 0) {
    func_0x002c1d28(uVar2,0x2e,uRam0000000000e99928,(long)iVar7);
  }
  *(undefined4 *)(param_1 + 0x1c) = 20000;
  return;
}



// ===== function 0x27e350 =====

void FUN_0027e350(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  uint *puVar4;
  uint *puVar5;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  
  puVar5 = (uint *)(ulong)uRam0000000000e997e0;
  uVar3 = (ulong)*puVar5;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(uVar3 + 0xc);
  func_0x002c1880(uVar3,0);
  func_0x0027c1b8(uRam0000000000e99948);
  puVar4 = (uint *)(ulong)uRam0000000000e997d4;
  auStack_50 = (undefined1  [16])0x0;
  auStack_60 = (undefined1  [16])0x0;
  auStack_40 = (undefined1  [16])0x0;
  uVar1 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar4 + 0x9e8))
                    ((uint *)(ulong)*puVar4);
  auStack_40._8_4_ = uVar1;
  uVar1 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar4 + 0x9e4))
                    ((uint *)(ulong)*puVar4);
  auStack_40._12_4_ = uVar1;
  func_0x0071b048(auStack_50 + 5,param_1 + 0x78U & 0xffffffff);
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar4 + 0x714))
            ((uint *)(ulong)*puVar4,0xffffffffffffffff);
  uVar1 = uRam0000000000e9994c;
  *(undefined4 *)(param_1 + 0x1c) = 30000;
  iVar2 = func_0x0071d598(auStack_60,uVar1,0,param_1 + 8U & 0xffffffff);
  *(int *)(param_1 + 0x334) = iVar2;
  if (iVar2 != 0) {
    func_0x002c1d28(*puVar5,0xc,uRam0000000000e99950);
  }
  return;
}



// ===== function 0x2a0df8 =====

void FUN_002a0df8(long param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x78);
  if (iVar1 == 1) {
    func_0x0027c1b8(uRam0000000000e9a32c,uRam0000000000e9a330);
    func_0x0029e860(param_1,0,0);
    func_0x0029ea98(param_1,0);
    goto LAB_002a0e30;
  }
  if (iVar1 < 2) {
    if (iVar1 != 0) goto LAB_002a0e30;
  }
  else {
    if (iVar1 == 2) {
      func_0x0027c1b8(uRam0000000000e9a334,uRam0000000000e9a330);
      func_0x0029ff78(param_1,0,0);
      func_0x0029f968(param_1,0);
      goto LAB_002a0e30;
    }
    if (iVar1 != 3) goto LAB_002a0e30;
  }
  func_0x0027c1b8(uRam0000000000e9a338,uRam0000000000e9a330);
LAB_002a0e30:
  if (*(int *)(param_1 + 0x44) != 0) {
    func_0x0071b0c8(*(int *)(param_1 + 0x44));
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  return;
}



