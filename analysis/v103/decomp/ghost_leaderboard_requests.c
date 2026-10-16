// ===== function 0x2c9900 =====

undefined8 FUN_002c9900(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 in_LR;
  
  func_0x002d0568(param_1,uRam0000000000e9ab9c /* 'ghost' */);
  uVar1 = uRam0000000000e9ac6c;
  param_1[0xb] = 0;
  *param_1 = uVar1;
  *(undefined1 *)(param_1 + 0xc) = 0;
  puVar2 = (undefined4 *)func_0x0071b0b8(0x2c);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  *(undefined1 *)(puVar2 + 5) = 0;
  param_1[10] = (int)puVar2;
  puVar2[9] = 0;
  puVar2[10] = 0xf;
  return in_LR;
}



// ===== function 0x2caf88 =====

undefined8 FUN_002caf88(ulong param_1,undefined4 param_2)

{
  ulong uVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined8 in_LR;
  
  lVar2 = func_0x0071d738();
  uVar3 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar2 + 0x1c))(param_2);
  iVar4 = func_0x0071b2d8(uVar3,uRam0000000000e9ab9c /* 'ghost' */);
  if (iVar4 == 0) {
    lVar2 = func_0x0071d738();
    uVar1 = param_1 & 0xffffffff;
    uVar3 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar2 + 0x68))(param_2,uRam0000000000e9accc /* 'data' */);
    lVar2 = func_0x0071d738();
    uVar3 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar2 + 0xc))(uVar3);
    iVar4 = func_0x002cabb8(uVar1,uVar3);
    if (iVar4 != 0) {
      *(int *)(param_1 + 0x2c) = iVar4;
      func_0x0021e9e8(iVar4);
      uVar3 = *(undefined4 *)((ulong)*(uint *)(param_1 + 0x2c) + 4);
      uVar5 = func_0x0021ea20((ulong)*(uint *)(param_1 + 0x2c));
      uVar6 = func_0x0021ea00(*(undefined4 *)(param_1 + 0x2c));
      uVar7 = func_0x0021ea38(*(undefined4 *)(param_1 + 0x2c));
      uVar8 = func_0x0021ea68(*(undefined4 *)(param_1 + 0x2c));
      iVar4 = func_0x0021e838(*(undefined4 *)(param_1 + 0x2c));
      iVar9 = func_0x0021e838(*(undefined4 *)(param_1 + 0x2c));
      func_0x0027c1b8(uRam0000000000e9acd0 /* 'Ghost: Buffer size %d, Current time %d, Split 1 time %d, Split 2 time %d, Split 3 time %d,' */,uVar3,uVar5,uVar6,uVar7,uVar8,iVar4 + 0x28,iVar9 + 8);
      lVar2 = func_0x0021e838(*(undefined4 *)(param_1 + 0x2c));
      if ((((*(char *)(lVar2 + 8) != '\0') &&
           (lVar2 = func_0x0021e838(*(undefined4 *)(param_1 + 0x2c)),
           *(char *)(lVar2 + 0x48) != '\0')) &&
          (*(int *)((ulong)*(uint *)(param_1 + 0x2c) + 4) != 0)) &&
         (((iVar4 = func_0x0021ea20(), iVar4 != 0 &&
           (iVar4 = func_0x0021ea00(*(undefined4 *)(param_1 + 0x2c)), iVar4 != 0)) &&
          ((iVar4 = func_0x0021ea38(*(undefined4 *)(param_1 + 0x2c)), iVar4 != 0 &&
           (iVar4 = func_0x0021ea68(*(undefined4 *)(param_1 + 0x2c)), iVar4 != 0)))))) {
        *(undefined4 *)(ulong)uRam0000000000e9acd4 = *(undefined4 *)(param_1 + 0x2c);
        func_0x002d0358(uVar1,0);
        return in_LR;
      }
      func_0x002d02c8(uVar1,0xffffffffffffffff,uRam0000000000e9acdc /* 'GHOST DATA CORRUPT' */,0x50);
      return in_LR;
    }
    func_0x002d02c8(uVar1,0xffffffffffffffff,uRam0000000000e9acd8 /* 'NO GHOST DATA' */,0x50);
  }
  return in_LR;
}



// ===== function 0x2cbcc8 =====

uint FUN_002cbcc8(ulong param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  uint *puVar4;
  undefined4 uVar9;
  undefined4 uVar10;
  uint *puVar5;
  uint uVar11;
  long lVar6;
  uint uVar12;
  ulong uVar7;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  uint *puVar8;
  uint uVar16;
  undefined1 *puVar17;
  ulong uVar18;
  uint *puVar19;
  uint *puVar20;
  int *piVar21;
  int iStack_540;
  undefined1 auStack_53c [4];
  int iStack_538;
  undefined4 uStack_534;
  undefined4 uStack_530;
  undefined1 auStack_52c [4];
  int iStack_528;
  undefined4 uStack_524;
  undefined4 uStack_520;
  undefined1 auStack_518 [24];
  undefined1 auStack_500 [4];
  undefined4 auStack_4fc [4];
  uint uStack_4ec;
  uint uStack_4e8;
  undefined1 auStack_4e4 [4];
  uint uStack_4e0;
  undefined4 uStack_4d0;
  uint uStack_4cc;
  undefined1 auStack_4c8 [64];
  undefined1 auStack_488 [1032];
  
  uVar10 = uRam0000000000e9acfc /* 'Request counts are %d %d' */;
  uVar7 = param_1 & 0xffffffff;
  uVar18 = (ulong)auStack_488 & 0xffffffff;
  *(undefined1 *)(param_1 + 0x54) = 1;
  func_0x0027c1b8(uVar10,(long)*(int *)(param_1 + 0x50),
                  (long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 0x18));
  *(undefined4 *)((ulong)*(uint *)(param_1 + 0x28) + 0x18) = *(undefined4 *)(param_1 + 0x50);
  func_0x002ca838(auStack_500,uVar7);
  func_0x0071d708(uVar18);
  uVar3 = (ulong)auStack_4c8 & 0xffffffff;
  uVar9 = func_0x002d0098(uVar7,(long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 0xc),uVar3);
  uVar10 = uRam0000000000e9ab88 /* 'source/online/svo/ms2actions.cpp' */;
  func_0x0071d718(uVar18,uRam0000000000e9ab88 /* 'source/online/svo/ms2actions.cpp' */,0x145,uRam0000000000e9ad00 /* 'location.region' */,uVar9);
  uVar9 = func_0x002d0098(uVar7,(long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 0x10),uVar3);
  func_0x0071d718(uVar18,uVar10,0x148,uRam0000000000e9ad04,uVar9);
  uVar9 = func_0x002d0098(uVar7,(long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 0x14),uVar3);
  func_0x0071d718(uVar18,uVar10,0x149,uRam0000000000e9ad08 /* 'pageSize' */,uVar9);
  uVar11 = *(uint *)(param_1 + 0x28);
  piVar21 = (int *)(ulong)uVar11;
  if (piVar21[7] != 2) {
    if (piVar21[7] == 1) {
      func_0x0071d718(uVar18,uVar10,0x151,uRam0000000000e9ad10 /* 'myPosition' */,uRam0000000000e9abc0 /* 'true' */);
      goto LAB_002cc6dc;
    }
    if (*(char *)(piVar21 + 10) != '\0') goto LAB_002cbfc8;
    iVar15 = piVar21[2];
    if (iVar15 == 9) goto LAB_002cc1f0;
    if (iVar15 == 0xb) goto LAB_002cc79c;
    if (iVar15 == 5) goto LAB_002cc06c;
    func_0x0027c1b8(uRam0000000000e9ad68 /* 'Getting leaderboard %d %d %d' */,(long)iVar15,(long)*piVar21,(long)piVar21[1]);
    uVar9 = func_0x002d0098(uVar7,(long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 8),uVar3);
    func_0x0071d718(uVar18,uVar10,0x1c0,uRam0000000000e9ab8c /* 'location.gameMode' */,uVar9);
LAB_002cbee0:
    uVar7 = (ulong)auStack_488 & 0xffffffff;
    uVar10 = func_0x00792338(param_2);
    puVar5 = (uint *)func_0x00792378(uVar10);
    uVar11 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar5 + 0x14))
                       ((ulong)puVar5 & 0xffffffff,uRam0000000000e9ad6c /* 'leaderboard' */,7,uVar7,0,0,0);
    uVar11 = ((int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f ^ uVar11) >> 0x1f;
    func_0x0071d728(uVar7);
    goto LAB_002cbf54;
  }
  func_0x0071d718(uVar18,uVar10,0x14d,uRam0000000000e9ad0c /* 'friends' */,uRam0000000000e9abc0 /* 'true' */);
LAB_002cc6dc:
  uVar11 = *(uint *)(param_1 + 0x28);
  piVar21 = (int *)(ulong)uVar11;
  if (*(char *)(piVar21 + 10) == '\0') {
    iVar15 = piVar21[2];
    if (iVar15 == 9) goto LAB_002cc1f0;
    if (iVar15 != 0xb) {
      if (iVar15 == 5) {
LAB_002cc06c:
        iStack_540 = 0;
        lVar6 = func_0x002b6db0();
        uVar12 = func_0x00244660(*(undefined4 *)(lVar6 + 0x10),uRam0000000000e9ad4c /* 'Online.ranked.ranking' */,
                                 (ulong)&iStack_540 & 0xffffffff,0);
        uVar11 = *(uint *)(param_1 + 0x28);
        piVar21[8] = uVar12 & 0xff;
        lVar6 = func_0x002b6db0();
        uVar12 = func_0x00244660(*(undefined4 *)(lVar6 + 0x10),uRam0000000000e9ad50 /* 'Online.ranked.playersbeaten' */,
                                 (ulong)&iStack_540 & 0xffffffff,0);
        uVar9 = uRam0000000000e9ad54 /* 'Querying ranked, local score is %d' */;
        iVar15 = *(int *)((ulong)*(uint *)(param_1 + 0x28) + 0x20);
        *(uint *)((ulong)uVar11 + 0x24) = uVar12 & 0xff;
        func_0x0027c1b8(uVar9,(long)iVar15);
        uVar7 = (ulong)auStack_4c8 & 0xffffffff;
        uVar9 = func_0x002d0098(param_1 & 0xffffffff,
                                (long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 0x20),uVar7);
        puVar17 = (undefined1 *)((ulong)auStack_488 & 0xffffffff);
        func_0x0071d718(puVar17,uVar10,0x1b7,uRam0000000000e9ad58 /* 'stat.score' */,uVar9);
        uVar9 = func_0x002d0098(param_1 & 0xffffffff,
                                (long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 0x24),uVar7);
        func_0x0071d718(puVar17,uVar10,0x1b8,uRam0000000000e9ad5c /* 'stat.playersBeaten' */,uVar9);
        func_0x0027c1b8(uRam0000000000e9ad60 /* 'Getting ranked leaderboard' */);
        uVar10 = func_0x00792338(param_2);
        puVar5 = (uint *)func_0x00792378(uVar10);
        uVar7 = (ulong)puVar5 & 0xffffffff;
        uVar10 = uRam0000000000e9ad64 /* 'leaderboard/ranked' */;
      }
      else {
        func_0x0027c1b8(uRam0000000000e9ad68 /* 'Getting leaderboard %d %d %d' */,(long)iVar15,(long)*piVar21,(long)piVar21[1]);
        uVar9 = func_0x002d0098(param_1 & 0xffffffff,
                                (long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 8),auStack_4c8);
        puVar17 = (undefined1 *)((ulong)auStack_488 & 0xffffffff);
        func_0x0071d718(puVar17,uVar10,0x1c0,uRam0000000000e9ab8c /* 'location.gameMode' */,uVar9);
        uVar10 = func_0x00792338(param_2);
        puVar5 = (uint *)func_0x00792378(uVar10);
        uVar7 = (ulong)puVar5 & 0xffffffff;
        uVar10 = uRam0000000000e9ad6c /* 'leaderboard' */;
      }
      goto LAB_002cc1a4;
    }
LAB_002cc79c:
    uVar7 = param_1 & 0xffffffff;
    uVar18 = (ulong)auStack_4c8 & 0xffffffff;
    uVar9 = func_0x002d0098(uVar7,(long)*piVar21,uVar18);
    uVar3 = (ulong)auStack_488 & 0xffffffff;
    func_0x0071d718(uVar3,uVar10,0x191,uRam0000000000e9ab94 /* 'location.track' */,uVar9);
    iVar15 = FUN_002c20f8((long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 4));
    uVar9 = func_0x002d0098(uVar7,(long)iVar15,uVar18);
    func_0x0071d718(uVar3,uVar10,0x192,uRam0000000000e9ab90 /* 'location.vehicle' */,uVar9);
    lVar6 = func_0x002b6db0();
    uVar9 = *(undefined4 *)(lVar6 + 0x10);
    uVar18 = (ulong)auStack_518 & 0xffffffff;
    func_0x00bdf650(uVar18,uRam0000000000e9ad34 /* 'ticket.%d.%d.best_time' */,(long)*(int *)(ulong)*(uint *)(param_1 + 0x28),
                    (long)((int *)(ulong)*(uint *)(param_1 + 0x28))[1]);
    iStack_540 = 0;
    func_0x0074a310((ulong)auStack_4e4 & 0xffffffff,uVar18);
    func_0x002444d8(uVar9,(ulong)auStack_4e4 & 0xffffffff,&iStack_540,0);
    if (0xf < uStack_4cc) {
      func_0x0071b0c8(uStack_4e0);
    }
    uStack_4cc = 0xf;
    uStack_4e0 = uStack_4e0 & 0xffffff;
    uStack_4d0 = 0;
    func_0x0027c1b8(uRam0000000000e9ad38 /* 'Getting sw best time %s, %d' */,auStack_518,(long)iStack_540);
    if (0 < iStack_540) {
      uVar18 = (ulong)auStack_4c8 & 0xffffffff;
      uVar9 = func_0x002d0098(uVar7,(long)iStack_540,uVar18);
      uVar3 = (ulong)auStack_488 & 0xffffffff;
      func_0x0071d718(uVar3,uVar10,0x19c,uRam0000000000e9ad3c /* 'stat.timeRemaining' */,uVar9);
      iVar15 = FUN_002c20f8((long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 4));
      uVar9 = func_0x002d0098(uVar7,(long)iVar15,uVar18);
      func_0x0071d718(uVar3,uVar10,0x19d,uRam0000000000e9ad24 /* 'stat.vehicle' */,uVar9);
    }
    uVar11 = uStack_4e8;
    uVar10 = auStack_4fc[0];
    puVar20 = (uint *)(ulong)*(uint *)(param_1 + 0x48);
    puVar19 = (uint *)(ulong)*(uint *)((ulong)*(uint *)(param_1 + 0x48) + 4);
    puVar5 = puVar20;
    puVar8 = puVar19;
    if (uStack_4e8 < 0x10) {
LAB_002cc988:
      puVar4 = puVar5;
      if (*(char *)((long)puVar8 + 0x39) == '\0') {
        do {
          puVar5 = puVar8;
          uVar18 = (ulong)(puVar5 + 3) & 0xffffffff;
          uVar12 = *(uint *)(uVar18 + 0x14);
          if (uVar12 == 0) {
LAB_002ccb70:
            uVar16 = (int)(uVar12 ^ uStack_4ec) >> 0x1f;
            uVar16 = uVar16 - (uVar16 ^ uVar12 ^ uStack_4ec) >> 0x1f;
            if (uVar12 < uStack_4ec) goto LAB_002ccb8c;
          }
          else {
            puVar8 = puVar5 + 4;
            if (0xf < *(uint *)(uVar18 + 0x18)) {
              puVar8 = (uint *)(ulong)*(uint *)(uVar18 + 4);
            }
            uVar16 = uVar12;
            if (uStack_4ec < uVar12) {
              uVar16 = uStack_4ec;
            }
            uVar16 = func_0x0071b318((ulong)puVar8 & 0xffffffff,(ulong)auStack_4fc & 0xffffffff,
                                     uVar16);
            if (uVar16 == 0) goto LAB_002ccb70;
          }
          if ((int)uVar16 < 0) goto LAB_002ccb8c;
          puVar4 = puVar5;
          puVar8 = (uint *)(ulong)*puVar5;
          if (*(char *)((ulong)*puVar5 + 0x39) != '\0') break;
        } while( true );
      }
      goto LAB_002cca0c;
    }
    while (*(char *)((long)puVar8 + 0x39) == '\0') {
      uVar18 = (ulong)(puVar8 + 3) & 0xffffffff;
      uVar12 = *(uint *)(uVar18 + 0x14);
      if (uVar12 == 0) {
LAB_002ccfa0:
        uVar16 = (int)(uVar12 ^ uStack_4ec) >> 0x1f;
        uVar16 = uVar16 - (uVar16 ^ uVar12 ^ uStack_4ec) >> 0x1f;
        if (uStack_4ec <= uVar12) goto LAB_002cd04c;
LAB_002ccfbc:
        puVar8 = (uint *)(ulong)puVar8[2];
      }
      else {
        if (*(uint *)(uVar18 + 0x18) < 0x10) {
          puVar4 = puVar8 + 4;
        }
        else {
          puVar4 = (uint *)(ulong)*(uint *)(uVar18 + 4);
        }
        uVar16 = uVar12;
        if (uStack_4ec < uVar12) {
          uVar16 = uStack_4ec;
        }
        uVar16 = func_0x0071b318((ulong)puVar4 & 0xffffffff,uVar10,uVar16);
        if (uVar16 == 0) goto LAB_002ccfa0;
LAB_002cd04c:
        if ((int)uVar16 < 0) goto LAB_002ccfbc;
        puVar5 = puVar8;
        puVar8 = (uint *)(ulong)*puVar8;
      }
    }
LAB_002cca0c:
    if (uStack_4ec == 0) {
      if (uVar11 < 0x10) {
        while (uVar11 = (uint)puVar20, *(char *)((long)puVar19 + 0x39) == '\0') {
          while (puVar8 = puVar19, puVar8[8] != 0) {
            uVar11 = (uint)puVar8;
            puVar19 = (uint *)(ulong)*puVar8;
            puVar20 = puVar8;
            if (*(char *)((ulong)*puVar8 + 0x39) != '\0') goto LAB_002cca5c;
          }
          puVar19 = (uint *)(ulong)puVar8[2];
        }
      }
      else {
        while (uVar11 = (uint)puVar20, *(char *)((long)puVar19 + 0x39) == '\0') {
          if (puVar19[8] == 0) {
            uVar11 = puVar19[2];
          }
          else {
            uVar11 = *puVar19;
            puVar20 = puVar19;
          }
          puVar19 = (uint *)(ulong)uVar11;
        }
      }
    }
    else if (uVar11 < 0x10) {
      while (puVar8 = puVar19, uVar11 = (uint)puVar20, *(char *)((long)puVar8 + 0x39) == '\0') {
        puVar19 = puVar8 + 4;
        uVar18 = (ulong)(puVar8 + 3) & 0xffffffff;
        if (0xf < *(uint *)(uVar18 + 0x18)) {
          puVar19 = (uint *)(ulong)*(uint *)(uVar18 + 4);
        }
        uVar11 = *(uint *)(uVar18 + 0x14);
        uVar12 = uVar11;
        if (uStack_4ec < uVar11) {
          uVar12 = uStack_4ec;
        }
        uVar12 = func_0x0071b318((ulong)auStack_4fc & 0xffffffff,(ulong)puVar19 & 0xffffffff,uVar12)
        ;
        if (((uVar12 == 0) &&
            (uVar12 = (int)(uVar11 ^ uStack_4ec) >> 0x1f,
            uVar12 = uVar12 - (uVar12 ^ uVar11 ^ uStack_4ec) >> 0x1f, uStack_4ec < uVar11)) ||
           ((int)uVar12 < 0)) {
          puVar19 = (uint *)(ulong)*puVar8;
          puVar20 = puVar8;
        }
        else {
          puVar19 = (uint *)(ulong)puVar8[2];
        }
      }
    }
    else {
      while (puVar8 = puVar19, uVar11 = (uint)puVar20, *(char *)((long)puVar8 + 0x39) == '\0') {
        uVar18 = (ulong)(puVar8 + 3) & 0xffffffff;
        if (*(uint *)(uVar18 + 0x18) < 0x10) {
          puVar19 = puVar8 + 4;
        }
        else {
          puVar19 = (uint *)(ulong)*(uint *)(uVar18 + 4);
        }
        uVar11 = *(uint *)(uVar18 + 0x14);
        uVar12 = uVar11;
        if (uVar11 > uStack_4ec) {
          uVar12 = uStack_4ec;
        }
        uVar12 = func_0x0071b318(uVar10,(ulong)puVar19 & 0xffffffff,uVar12);
        if (uVar12 == 0) {
          if (uVar11 <= uStack_4ec) {
            uVar12 = (int)(uVar11 ^ uStack_4ec) >> 0x1f;
            uVar12 = uVar12 - (uVar12 ^ uVar11 ^ uStack_4ec) >> 0x1f;
            goto LAB_002cd000;
          }
LAB_002ccf60:
          puVar19 = (uint *)(ulong)*puVar8;
          puVar20 = puVar8;
        }
        else {
LAB_002cd000:
          if ((int)uVar12 < 0) goto LAB_002ccf60;
          puVar19 = (uint *)(ulong)puVar8[2];
        }
      }
    }
LAB_002cca5c:
    bVar1 = uVar11 == (uint)puVar5;
    iVar15 = 0;
    while (!bVar1) {
      if (*(char *)((long)puVar5 + 0x39) == '\0') {
        puVar19 = (uint *)(ulong)puVar5[2];
        uVar12 = puVar5[2];
        if (*(char *)((long)puVar19 + 0x39) == '\0') {
          do {
            uVar16 = uVar12;
            puVar5 = (uint *)(ulong)uVar16;
            uVar12 = *puVar19;
            puVar19 = (uint *)(ulong)uVar12;
          } while (*(char *)((long)puVar19 + 0x39) == '\0');
          bVar1 = uVar11 == uVar16;
        }
        else {
          puVar19 = (uint *)(ulong)puVar5[1];
          uVar18 = (ulong)puVar5[1];
          if ((*(char *)(uVar18 + 0x39) == '\0') && (*(int *)(uVar18 + 8) == (int)puVar5)) {
            do {
              iVar2 = (int)puVar19;
              puVar19 = (uint *)(ulong)*(uint *)(uVar18 + 4);
              uVar18 = (ulong)*(uint *)(uVar18 + 4);
              if (*(char *)(uVar18 + 0x39) != '\0') break;
            } while (*(int *)(uVar18 + 8) == iVar2);
          }
          puVar5 = puVar19;
          bVar1 = uVar11 == (uint)puVar5;
        }
      }
      iVar15 = iVar15 + 1;
    }
    if (iVar15 == 0) {
      func_0x0027c1b8(uRam0000000000e9ad44 /* 'Getting speed weekend leaderboard %d %d' */,(long)*(int *)(ulong)*(uint *)(param_1 + 0x28),
                      (long)((int *)(ulong)*(uint *)(param_1 + 0x28))[1]);
      uVar10 = func_0x00792338(param_2);
      puVar5 = (uint *)func_0x00792378(uVar10);
      uVar10 = uRam0000000000e9ad48 /* 'leaderboard/speed' */;
      goto LAB_002cc668;
    }
    func_0x0027c1b8(uRam0000000000e9ad40 /* 'Getting cached speed weekend leaderboard %d %d' */,(long)*(int *)(ulong)*(uint *)(param_1 + 0x28),
                    (long)((int *)(ulong)*(uint *)(param_1 + 0x28))[1]);
    iVar15 = *(int *)(param_1 + 0x28);
    uVar10 = func_0x008a0310(param_1 + 0x44 & 0xffffffff,auStack_500);
    func_0x0084cac0((ulong)auStack_53c & 0xffffffff,uVar10);
    func_0x0089bea0(iVar15 + 0x6c,(ulong)auStack_53c & 0xffffffff);
    if (iStack_538 != 0) {
      func_0x0071b0c8(iStack_538);
    }
    uStack_530 = 0;
    iStack_538 = 0;
    uStack_534 = 0;
    func_0x002d0358(uVar7,0);
    uVar11 = 1;
  }
  else {
LAB_002cbfc8:
    uVar7 = (ulong)auStack_488 & 0xffffffff;
    func_0x0071d718(uVar7,uVar10,0x15a,uRam0000000000e9ac8c /* 'accountName' */,uVar11 + 0x28);
    piVar21 = (int *)(ulong)*(uint *)(param_1 + 0x28);
    iVar15 = piVar21[2];
    if (iVar15 != 9) {
      if (iVar15 == 0xb) goto LAB_002cc79c;
      if (iVar15 == 5) goto LAB_002cc06c;
      func_0x0027c1b8(uRam0000000000e9ad68 /* 'Getting leaderboard %d %d %d' */,(long)iVar15,(long)*piVar21,(long)piVar21[1]);
      uVar9 = func_0x002d0098(param_1 & 0xffffffff,
                              (long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 8),auStack_4c8);
      func_0x0071d718(uVar7,uVar10,0x1c0,uRam0000000000e9ab8c /* 'location.gameMode' */,uVar9);
      goto LAB_002cbee0;
    }
LAB_002cc1f0:
    uVar7 = param_1 & 0xffffffff;
    uVar18 = (ulong)auStack_4c8 & 0xffffffff;
    uVar9 = func_0x002d0098(uVar7,(long)*piVar21,uVar18);
    uVar3 = (ulong)auStack_488 & 0xffffffff;
    func_0x0071d718(uVar3,uVar10,0x15f,uRam0000000000e9ab94 /* 'location.track' */,uVar9);
    iVar15 = FUN_002c20f8((long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 4));
    uVar9 = func_0x002d0098(uVar7,(long)iVar15,uVar18);
    func_0x0071d718(uVar3,uVar10,0x160,uRam0000000000e9ab90 /* 'location.vehicle' */,uVar9);
    lVar6 = func_0x002b6db0();
    iVar2 = *(int *)(lVar6 + 0x18) + 0x338;
    uVar9 = *(undefined4 *)(ulong)*(uint *)(param_1 + 0x28);
    iVar15 = ((undefined4 *)(ulong)*(uint *)(param_1 + 0x28))[1];
    uVar13 = func_0x0020a858(iVar2);
    uVar14 = func_0x0020a848(iVar2);
    func_0x0027c1b8(uRam0000000000e9ad14 /* 'Querying time trial, track %d, vehicle %d' */,uVar9,iVar15);
    if (*(int *)((ulong)*(uint *)(param_1 + 0x28) + 4) < 8) {
      uVar11 = func_0x0020b930(iVar2,uVar9,iVar15,1);
    }
    else {
      uVar11 = func_0x0020b930(iVar2,uVar9,0,1);
      uVar12 = func_0x0020b930(iVar2,uVar9,1,1);
      if ((uVar11 == 0) || (iVar15 = 0, uVar12 < uVar11)) {
        iVar15 = 1;
        uVar11 = uVar12;
      }
      uVar12 = func_0x0020b930(iVar2,uVar9,2,1);
      if ((uVar11 == 0) || (uVar12 < uVar11)) {
        iVar15 = 2;
        uVar11 = uVar12;
      }
      uVar12 = func_0x0020b930(iVar2,uVar9,3,1);
      if ((uVar11 == 0) || (uVar12 < uVar11)) {
        iVar15 = 3;
        uVar11 = uVar12;
      }
      uVar12 = func_0x0020b930(iVar2,uVar9,4,1);
      if ((uVar11 == 0) || (uVar12 < uVar11)) {
        iVar15 = 4;
        uVar11 = uVar12;
      }
      uVar12 = func_0x0020b930(iVar2,uVar9,5,1);
      if ((uVar11 == 0) || (uVar12 < uVar11)) {
        iVar15 = 5;
        uVar11 = uVar12;
      }
      uVar12 = func_0x0020b930(iVar2,uVar9,6,1);
      if ((uVar11 == 0) || (uVar12 < uVar11)) {
        iVar15 = 6;
        uVar11 = uVar12;
      }
      uVar12 = func_0x0020b930(iVar2,uVar9,7,1);
      if ((uVar11 == 0) || (uVar12 < uVar11)) {
        iVar15 = 7;
        uVar11 = uVar12;
      }
    }
    func_0x00213a80(iVar2,uVar14);
    func_0x0020a838(iVar2,uVar13);
    uVar9 = func_0x0020a848(iVar2);
    uVar13 = func_0x0020a858(iVar2);
    func_0x0027c1b8(uRam0000000000e9ad18 /* 'Restoring time trial, track %d, vehicle %d' */,uVar9,uVar13);
    func_0x0027c1b8(uRam0000000000e9ad1c /* 'Querying time trial, track best %d' */,uVar11);
    if (uVar11 - 1 < 0x98967e) {
      uVar18 = (ulong)auStack_4c8 & 0xffffffff;
      uVar9 = func_0x002d0098(uVar7,(long)(int)uVar11,uVar18);
      uVar3 = (ulong)auStack_488 & 0xffffffff;
      func_0x0071d718(uVar3,uVar10,0x182,uRam0000000000e9ad20 /* 'stat.bestTime' */,uVar9);
      iVar15 = FUN_002c20f8((long)iVar15);
      uVar9 = func_0x002d0098(uVar7,(long)iVar15,uVar18);
      func_0x0071d718(uVar3,uVar10,0x183,uRam0000000000e9ad24 /* 'stat.vehicle' */,uVar9);
    }
    uVar11 = uStack_4e8;
    uVar10 = auStack_4fc[0];
    puVar20 = (uint *)(ulong)*(uint *)(param_1 + 0x3c);
    puVar19 = (uint *)(ulong)*(uint *)((ulong)*(uint *)(param_1 + 0x3c) + 4);
    puVar5 = puVar20;
    puVar8 = puVar19;
    if (uStack_4e8 < 0x10) {
LAB_002cc4c0:
      puVar4 = puVar5;
      if (*(char *)((long)puVar8 + 0x39) == '\0') {
        do {
          puVar5 = puVar8;
          uVar18 = (ulong)(puVar5 + 3) & 0xffffffff;
          uVar12 = *(uint *)(uVar18 + 0x14);
          if (uVar12 == 0) {
LAB_002cc6a8:
            if (uVar12 < uStack_4ec) goto LAB_002cc6b0;
          }
          else {
            puVar8 = puVar5 + 4;
            if (0xf < *(uint *)(uVar18 + 0x18)) {
              puVar8 = (uint *)(ulong)*(uint *)(uVar18 + 4);
            }
            uVar16 = uVar12;
            if (uStack_4ec < uVar12) {
              uVar16 = uStack_4ec;
            }
            iVar15 = func_0x0071b318((ulong)puVar8 & 0xffffffff,(ulong)auStack_4fc & 0xffffffff,
                                     uVar16);
            if (iVar15 == 0) goto LAB_002cc6a8;
            if (iVar15 < 0) goto LAB_002cc6b0;
          }
          puVar4 = puVar5;
          puVar8 = (uint *)(ulong)*puVar5;
          if (*(char *)((ulong)*puVar5 + 0x39) != '\0') break;
        } while( true );
      }
      goto LAB_002cc540;
    }
    while (*(char *)((long)puVar8 + 0x39) == '\0') {
      uVar18 = (ulong)(puVar8 + 3) & 0xffffffff;
      uVar12 = *(uint *)(uVar18 + 0x14);
      if (uVar12 == 0) {
LAB_002cd298:
        uVar16 = (int)(uVar12 ^ uStack_4ec) >> 0x1f;
        uVar16 = uVar16 - (uVar16 ^ uVar12 ^ uStack_4ec) >> 0x1f;
        if (uStack_4ec <= uVar12) goto LAB_002cd304;
LAB_002cd2b4:
        puVar8 = (uint *)(ulong)puVar8[2];
      }
      else {
        if (*(uint *)(uVar18 + 0x18) < 0x10) {
          puVar4 = puVar8 + 4;
        }
        else {
          puVar4 = (uint *)(ulong)*(uint *)(uVar18 + 4);
        }
        uVar16 = uVar12;
        if (uStack_4ec < uVar12) {
          uVar16 = uStack_4ec;
        }
        uVar16 = func_0x0071b318((ulong)puVar4 & 0xffffffff,uVar10,uVar16);
        if (uVar16 == 0) goto LAB_002cd298;
LAB_002cd304:
        if ((int)uVar16 < 0) goto LAB_002cd2b4;
        puVar5 = puVar8;
        puVar8 = (uint *)(ulong)*puVar8;
      }
    }
LAB_002cc540:
    if (uStack_4ec == 0) {
      if (uVar11 < 0x10) {
        while (uVar11 = (uint)puVar20, *(char *)((long)puVar19 + 0x39) == '\0') {
          while (puVar8 = puVar19, puVar8[8] != 0) {
            uVar11 = (uint)puVar8;
            puVar19 = (uint *)(ulong)*puVar8;
            puVar20 = puVar8;
            if (*(char *)((ulong)*puVar8 + 0x39) != '\0') goto LAB_002cc58c;
          }
          puVar19 = (uint *)(ulong)puVar8[2];
        }
      }
      else {
        while (puVar8 = puVar19, uVar11 = (uint)puVar20, *(char *)((long)puVar8 + 0x39) == '\0') {
          if (puVar8[8] == 0) {
            puVar19 = (uint *)(ulong)puVar8[2];
          }
          else {
            puVar19 = (uint *)(ulong)*puVar8;
            puVar20 = puVar8;
          }
        }
      }
    }
    else if (uVar11 < 0x10) {
      while (uVar11 = (uint)puVar20, *(char *)((long)puVar19 + 0x39) == '\0') {
        puVar8 = puVar19 + 4;
        uVar18 = (ulong)(puVar19 + 3) & 0xffffffff;
        if (0xf < *(uint *)(uVar18 + 0x18)) {
          puVar8 = (uint *)(ulong)*(uint *)(uVar18 + 4);
        }
        uVar11 = *(uint *)(uVar18 + 0x14);
        uVar12 = uVar11;
        if (uStack_4ec < uVar11) {
          uVar12 = uStack_4ec;
        }
        uVar12 = func_0x0071b318((ulong)auStack_4fc & 0xffffffff,(ulong)puVar8 & 0xffffffff,uVar12);
        if (((uVar12 == 0) &&
            (uVar12 = (int)(uVar11 ^ uStack_4ec) >> 0x1f,
            uVar12 = uVar12 - (uVar12 ^ uVar11 ^ uStack_4ec) >> 0x1f, uStack_4ec < uVar11)) ||
           ((int)uVar12 < 0)) {
          uVar11 = *puVar19;
          puVar20 = puVar19;
        }
        else {
          uVar11 = puVar19[2];
        }
        puVar19 = (uint *)(ulong)uVar11;
      }
    }
    else {
      while (puVar8 = puVar19, uVar11 = (uint)puVar20, *(char *)((long)puVar8 + 0x39) == '\0') {
        uVar18 = (ulong)(puVar8 + 3) & 0xffffffff;
        if (*(uint *)(uVar18 + 0x18) < 0x10) {
          puVar19 = puVar8 + 4;
        }
        else {
          puVar19 = (uint *)(ulong)*(uint *)(uVar18 + 4);
        }
        uVar11 = *(uint *)(uVar18 + 0x14);
        uVar12 = uVar11;
        if (uVar11 > uStack_4ec) {
          uVar12 = uStack_4ec;
        }
        uVar12 = func_0x0071b318(uVar10,(ulong)puVar19 & 0xffffffff,uVar12);
        if (uVar12 == 0) {
          if (uVar11 <= uStack_4ec) {
            uVar12 = (int)(uVar11 ^ uStack_4ec) >> 0x1f;
            uVar12 = uVar12 - (uVar12 ^ uVar11 ^ uStack_4ec) >> 0x1f;
            goto LAB_002cd25c;
          }
LAB_002cd228:
          puVar19 = (uint *)(ulong)*puVar8;
          puVar20 = puVar8;
        }
        else {
LAB_002cd25c:
          if ((int)uVar12 < 0) goto LAB_002cd228;
          puVar19 = (uint *)(ulong)puVar8[2];
        }
      }
    }
LAB_002cc58c:
    bVar1 = uVar11 == (uint)puVar5;
    iVar15 = 0;
    while (!bVar1) {
      if (*(char *)((long)puVar5 + 0x39) == '\0') {
        puVar19 = (uint *)(ulong)puVar5[2];
        uVar12 = puVar5[2];
        if (*(char *)((long)puVar19 + 0x39) == '\0') {
          do {
            uVar16 = uVar12;
            puVar5 = (uint *)(ulong)uVar16;
            uVar12 = *puVar19;
            puVar19 = (uint *)(ulong)uVar12;
          } while (*(char *)((long)puVar19 + 0x39) == '\0');
          bVar1 = uVar11 == uVar16;
        }
        else {
          puVar19 = (uint *)(ulong)puVar5[1];
          uVar18 = (ulong)puVar5[1];
          if ((*(char *)(uVar18 + 0x39) == '\0') && (*(int *)(uVar18 + 8) == (int)puVar5)) {
            do {
              iVar2 = (int)puVar19;
              puVar19 = (uint *)(ulong)*(uint *)(uVar18 + 4);
              uVar18 = (ulong)*(uint *)(uVar18 + 4);
              if (*(char *)(uVar18 + 0x39) != '\0') break;
            } while (*(int *)(uVar18 + 8) == iVar2);
          }
          puVar5 = puVar19;
          bVar1 = uVar11 == (uint)puVar5;
        }
      }
      iVar15 = iVar15 + 1;
    }
    if (iVar15 == 0) {
      func_0x0027c1b8(uRam0000000000e9ad2c /* 'Getting time attack leaderboard %d %d' */,(long)*(int *)(ulong)*(uint *)(param_1 + 0x28),
                      (long)((int *)(ulong)*(uint *)(param_1 + 0x28))[1]);
      uVar10 = func_0x00792338(param_2);
      puVar5 = (uint *)func_0x00792378(uVar10);
      uVar10 = uRam0000000000e9ad30 /* 'leaderboard/timeattack' */;
LAB_002cc668:
      uVar7 = (ulong)puVar5 & 0xffffffff;
      puVar17 = auStack_488;
LAB_002cc1a4:
      uVar11 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar5 + 0x14))
                         (uVar7,uVar10,7,puVar17,0,0,0);
      uVar11 = ((int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f ^ uVar11) >> 0x1f;
    }
    else {
      func_0x0027c1b8(uRam0000000000e9ad28 /* 'Getting cached time attack leaderboard %d %d' */,(long)*(int *)(ulong)*(uint *)(param_1 + 0x28),
                      (long)((int *)(ulong)*(uint *)(param_1 + 0x28))[1]);
      iVar15 = *(int *)(param_1 + 0x28);
      uVar10 = func_0x0089f558(param_1 + 0x38 & 0xffffffff,auStack_500);
      func_0x0089d8d8((ulong)auStack_52c & 0xffffffff,uVar10);
      func_0x0089b708(iVar15 + 0x4c,(ulong)auStack_52c & 0xffffffff);
      if (iStack_528 != 0) {
        func_0x0071b0c8(iStack_528);
      }
      uStack_520 = 0;
      iStack_528 = 0;
      uStack_524 = 0;
      func_0x002d0358(uVar7,0);
      uVar11 = 1;
    }
  }
  func_0x0071d728(auStack_488);
LAB_002cbf54:
  if (0xf < uStack_4e8) {
    func_0x0071b0c8(auStack_4fc[0]);
  }
  return uVar11;
LAB_002cc6b0:
  puVar8 = puVar5 + 2;
  puVar5 = puVar4;
  puVar8 = (uint *)(ulong)*puVar8;
  goto LAB_002cc4c0;
LAB_002ccb8c:
  puVar8 = (uint *)(ulong)puVar5[2];
  puVar5 = puVar4;
  goto LAB_002cc988;
}



// ===== function 0x2cb258 =====

void FUN_002cb258(ulong param_1,int param_2,uint param_3,ulong param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  ulong uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  long lVar15;
  int iVar16;
  undefined4 uVar17;
  undefined1 *puVar18;
  int iVar19;
  long lVar20;
  uint uStack_160;
  undefined1 auStack_15c [4];
  int iStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined1 auStack_14c [4];
  undefined4 uStack_148;
  uint uStack_134;
  undefined1 auStack_130 [36];
  undefined4 uStack_10c;
  undefined1 auStack_108 [48];
  undefined1 uStack_d8;
  undefined4 uStack_d4;
  byte bStack_d0;
  byte bStack_cf;
  byte bStack_ce;
  undefined4 uStack_cc;
  int iStack_c8;
  int iStack_c0;
  ulong uStack_b8;
  uint uStack_b0;
  uint *puStack_a0;
  undefined1 *puStack_98;
  
  uVar14 = uRam0000000000e9acf4 /* 'estimated' */;
  uVar13 = uRam0000000000e9acf0 /* 'ghostAvailable' */;
  uVar12 = uRam0000000000e9acec /* 'currentPlayer' */;
  uVar11 = uRam0000000000e9ace8 /* 'rank' */;
  uVar10 = uRam0000000000e9ace4 /* 'bestTime' */;
  uVar9 = uRam0000000000e9ace0 /* 'accountId' */;
  uVar8 = uRam0000000000e9ac98 /* 'vehicle' */;
  uVar17 = uRam0000000000e9ac8c /* 'accountName' */;
  iStack_c0 = (int)param_1;
  uVar5 = param_4 & 0xffffffff;
  uStack_b8 = param_1;
  uStack_b0 = param_3;
  if (0 < param_2) {
    puStack_a0 = &uStack_160;
    puStack_98 = auStack_130;
    puVar6 = (undefined1 *)((ulong)auStack_108 & 0xffffffff);
    iVar19 = 0;
    lVar20 = 0;
    param_1 = param_1 & 0xffffffff;
    do {
      while( true ) {
        lVar15 = func_0x0071d738();
        puVar7 = (undefined4 *)(lVar20 + (ulong)uStack_b0 & 0xffffffff);
        (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar15 + 100))
                  (*puVar7,uVar17,(ulong)puStack_a0 & 0xffffffff);
        puVar18 = (undefined1 *)(ulong)uStack_160;
        uVar1 = puVar18[1];
        uVar2 = puVar18[2];
        uVar3 = puVar18[3];
        *puVar6 = *puVar18;
        puVar6[1] = uVar1;
        puVar6[2] = uVar2;
        puVar6[3] = uVar3;
        uVar1 = puVar18[5];
        uVar2 = puVar18[6];
        uVar3 = puVar18[7];
        puVar6[4] = puVar18[4];
        puVar6[5] = uVar1;
        puVar6[6] = uVar2;
        puVar6[7] = uVar3;
        uVar1 = puVar18[9];
        uVar2 = puVar18[10];
        uVar3 = puVar18[0xb];
        puVar6[8] = puVar18[8];
        puVar6[9] = uVar1;
        puVar6[10] = uVar2;
        puVar6[0xb] = uVar3;
        uVar1 = puVar18[0xd];
        uVar2 = puVar18[0xe];
        uVar3 = puVar18[0xf];
        puVar6[0xc] = puVar18[0xc];
        puVar6[0xd] = uVar1;
        puVar6[0xe] = uVar2;
        puVar6[0xf] = uVar3;
        uVar1 = puVar18[0x11];
        uVar2 = puVar18[0x12];
        uVar3 = puVar18[0x13];
        puVar6[0x10] = puVar18[0x10];
        puVar6[0x11] = uVar1;
        puVar6[0x12] = uVar2;
        puVar6[0x13] = uVar3;
        uVar1 = puVar18[0x15];
        uVar2 = puVar18[0x16];
        uVar3 = puVar18[0x17];
        puVar6[0x14] = puVar18[0x14];
        puVar6[0x15] = uVar1;
        puVar6[0x16] = uVar2;
        puVar6[0x17] = uVar3;
        uVar1 = puVar18[0x19];
        uVar2 = puVar18[0x1a];
        uVar3 = puVar18[0x1b];
        puVar6[0x18] = puVar18[0x18];
        puVar6[0x19] = uVar1;
        puVar6[0x1a] = uVar2;
        puVar6[0x1b] = uVar3;
        uVar1 = puVar18[0x1d];
        uVar2 = puVar18[0x1e];
        uVar3 = puVar18[0x1f];
        puVar6[0x1c] = puVar18[0x1c];
        puVar6[0x1d] = uVar1;
        puVar6[0x1e] = uVar2;
        puVar6[0x1f] = uVar3;
        uVar1 = puVar18[0x23];
        uVar2 = puVar18[0x21];
        uVar3 = puVar18[0x22];
        puVar6[0x20] = puVar18[0x20];
        puVar6[0x21] = uVar2;
        puVar6[0x22] = uVar3;
        puVar6[0x23] = uVar1;
        uVar1 = puVar18[0x25];
        uVar2 = puVar18[0x26];
        uVar3 = puVar18[0x27];
        puVar6[0x24] = puVar18[0x24];
        puVar6[0x25] = uVar1;
        puVar6[0x26] = uVar2;
        puVar6[0x27] = uVar3;
        uVar1 = puVar18[0x2b];
        uVar2 = puVar18[0x2a];
        uVar3 = puVar18[0x29];
        puVar6[0x28] = puVar18[0x28];
        puVar6[0x2b] = uVar1;
        puVar6[0x2a] = uVar2;
        puVar6[0x29] = uVar3;
        uVar1 = puVar18[0x2d];
        uVar2 = puVar18[0x2e];
        uVar3 = puVar18[0x2f];
        puVar6[0x2c] = puVar18[0x2c];
        puVar6[0x2d] = uVar1;
        puVar6[0x2e] = uVar2;
        puVar6[0x2f] = uVar3;
        uStack_d8 = 0;
        uStack_cc = func_0x002d04a0(param_1,*puVar7,uVar9);
        uStack_d4 = func_0x002d04a0(param_1,*puVar7,uVar10);
        uStack_10c = func_0x002d04a0(param_1,*puVar7,uVar11);
        iStack_c8 = func_0x002d04a0(param_1,*puVar7,uVar8);
        iStack_c8 = iStack_c8 + -1;
        lVar15 = func_0x002d04a0(param_1,*puVar7,uVar12);
        bStack_ce = (byte)((ulong)(((int)lVar15 >> 0x1f) - lVar15) >> 0x18) >> 7;
        iVar16 = func_0x002d04a0(param_1,*puVar7,uVar13);
        bStack_d0 = (byte)((uint)((iVar16 >> 0x1f) - iVar16) >> 0x1f);
        lVar15 = func_0x002d04a0(param_1,*puVar7,uVar14);
        iVar16 = *(int *)(param_4 + 4);
        bStack_cf = (byte)((ulong)(((int)lVar15 >> 0x1f) - lVar15) >> 0x18) >> 7;
        if (iVar16 != 0) break;
LAB_002cb628:
        iVar19 = iVar19 + 1;
        func_0x00877ee0(uVar5,*(undefined4 *)(param_4 + 8),1,(ulong)puStack_98 & 0xffffffff);
        lVar20 = lVar20 + 4;
        if (param_2 == iVar19) goto LAB_002cb654;
      }
      iVar4 = *(int *)(param_4 + 8);
      if ((uint)((*(int *)(param_4 + 0xc) - iVar16 >> 2) * 0x684bda13) <=
          (uint)((iVar4 - iVar16 >> 2) * 0x684bda13)) goto LAB_002cb628;
      if (iVar4 != 0) {
        func_0x0071b098(iVar4,(ulong)puStack_98 & 0xffffffff,0x6c);
      }
      iVar19 = iVar19 + 1;
      *(int *)(param_4 + 8) = iVar4 + 0x6c;
      lVar20 = lVar20 + 4;
    } while (param_2 != iVar19);
  }
LAB_002cb654:
  iVar19 = *(int *)(uStack_b8 + 0x28);
  func_0x0089d8d8((ulong)auStack_15c & 0xffffffff,uVar5);
  func_0x0089b708(iVar19 + 0x4c,(ulong)auStack_15c & 0xffffffff);
  if (iStack_158 != 0) {
    func_0x0071b0c8(iStack_158);
  }
  uStack_150 = 0;
  iStack_158 = 0;
  uStack_154 = 0;
  func_0x002ca838((ulong)auStack_14c & 0xffffffff,iStack_c0);
  uVar17 = func_0x0089f558(iStack_c0 + 0x38,(ulong)auStack_14c & 0xffffffff);
  func_0x0089b708(uVar17,uVar5);
  if (0xf < uStack_134) {
    func_0x0071b0c8(uStack_148);
  }
  return;
}



// ===== function 0x2cb7a8 =====

void FUN_002cb7a8(ulong param_1,int param_2,long param_3,ulong param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  ulong uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  long lVar14;
  int iVar15;
  undefined4 uVar16;
  undefined1 *puVar17;
  int iVar18;
  long lVar19;
  uint uStack_150;
  undefined1 auStack_14c [4];
  int iStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined1 auStack_13c [4];
  undefined4 uStack_138;
  uint uStack_124;
  undefined1 auStack_120 [36];
  undefined4 uStack_fc;
  undefined1 auStack_f8 [52];
  undefined4 uStack_c4;
  byte bStack_c0;
  byte bStack_bf;
  undefined4 uStack_bc;
  int iStack_b8;
  int iStack_b0;
  ulong uStack_a8;
  uint *puStack_a0;
  undefined1 *puStack_98;
  
  uVar13 = uRam0000000000e9acf8 /* 'timeRemaining' */;
  uVar12 = uRam0000000000e9acf4 /* 'estimated' */;
  uVar11 = uRam0000000000e9acec /* 'currentPlayer' */;
  uVar10 = uRam0000000000e9ace8 /* 'rank' */;
  uVar9 = uRam0000000000e9ace0 /* 'accountId' */;
  uVar8 = uRam0000000000e9ac98 /* 'vehicle' */;
  uVar16 = uRam0000000000e9ac8c /* 'accountName' */;
  iStack_b0 = (int)param_1;
  uVar5 = param_4 & 0xffffffff;
  uStack_a8 = param_1;
  if (0 < param_2) {
    puStack_a0 = &uStack_150;
    puStack_98 = auStack_120;
    puVar6 = (undefined1 *)((ulong)auStack_f8 & 0xffffffff);
    iVar18 = 0;
    lVar19 = 0;
    param_1 = param_1 & 0xffffffff;
    do {
      while( true ) {
        lVar14 = func_0x0071d738();
        puVar7 = (undefined4 *)(lVar19 + param_3 & 0xffffffff);
        (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar14 + 100))
                  (*puVar7,uVar16,(ulong)puStack_a0 & 0xffffffff);
        uStack_bc = func_0x002d04a0(param_1,*puVar7,uVar9);
        uStack_c4 = func_0x002d04a0(param_1,*puVar7,uVar13);
        uStack_fc = func_0x002d04a0(param_1,*puVar7,uVar10);
        iStack_b8 = func_0x002d04a0(param_1,*puVar7,uVar8);
        iStack_b8 = iStack_b8 + -1;
        iVar15 = func_0x002d04a0(param_1,*puVar7,uVar11);
        bStack_bf = (byte)((uint)((iVar15 >> 0x1f) - iVar15) >> 0x1f);
        lVar14 = func_0x002d04a0(param_1,*puVar7,uVar12);
        puVar17 = (undefined1 *)(ulong)uStack_150;
        bStack_c0 = (byte)((ulong)(((int)lVar14 >> 0x1f) - lVar14) >> 0x18) >> 7;
        uVar1 = puVar17[1];
        uVar2 = puVar17[2];
        uVar3 = puVar17[3];
        *puVar6 = *puVar17;
        puVar6[1] = uVar1;
        puVar6[2] = uVar2;
        puVar6[3] = uVar3;
        uVar1 = puVar17[5];
        uVar2 = puVar17[6];
        uVar3 = puVar17[7];
        puVar6[4] = puVar17[4];
        puVar6[6] = uVar2;
        puVar6[7] = uVar3;
        puVar6[5] = uVar1;
        uVar1 = puVar17[9];
        uVar2 = puVar17[10];
        uVar3 = puVar17[0xb];
        puVar6[8] = puVar17[8];
        puVar6[9] = uVar1;
        puVar6[10] = uVar2;
        puVar6[0xb] = uVar3;
        uVar1 = puVar17[0xd];
        uVar2 = puVar17[0xe];
        uVar3 = puVar17[0xf];
        puVar6[0xc] = puVar17[0xc];
        puVar6[0xd] = uVar1;
        puVar6[0xe] = uVar2;
        puVar6[0xf] = uVar3;
        uVar1 = puVar17[0x11];
        uVar2 = puVar17[0x12];
        uVar3 = puVar17[0x13];
        puVar6[0x10] = puVar17[0x10];
        puVar6[0x11] = uVar1;
        puVar6[0x12] = uVar2;
        puVar6[0x13] = uVar3;
        uVar1 = puVar17[0x15];
        uVar2 = puVar17[0x16];
        uVar3 = puVar17[0x17];
        puVar6[0x14] = puVar17[0x14];
        puVar6[0x15] = uVar1;
        puVar6[0x16] = uVar2;
        puVar6[0x17] = uVar3;
        uVar1 = puVar17[0x18];
        uVar2 = puVar17[0x1a];
        uVar3 = puVar17[0x1b];
        puVar6[0x19] = puVar17[0x19];
        puVar6[0x1a] = uVar2;
        puVar6[0x1b] = uVar3;
        puVar6[0x18] = uVar1;
        uVar1 = puVar17[0x1d];
        uVar2 = puVar17[0x1e];
        uVar3 = puVar17[0x1f];
        puVar6[0x1c] = puVar17[0x1c];
        puVar6[0x1d] = uVar1;
        puVar6[0x1e] = uVar2;
        puVar6[0x1f] = uVar3;
        uVar1 = puVar17[0x21];
        uVar2 = puVar17[0x22];
        uVar3 = puVar17[0x23];
        puVar6[0x20] = puVar17[0x20];
        puVar6[0x21] = uVar1;
        puVar6[0x22] = uVar2;
        puVar6[0x23] = uVar3;
        uVar1 = puVar17[0x25];
        uVar2 = puVar17[0x26];
        uVar3 = puVar17[0x27];
        puVar6[0x24] = puVar17[0x24];
        puVar6[0x25] = uVar1;
        puVar6[0x26] = uVar2;
        puVar6[0x27] = uVar3;
        uVar1 = puVar17[0x29];
        uVar2 = puVar17[0x2a];
        uVar3 = puVar17[0x2b];
        puVar6[0x28] = puVar17[0x28];
        puVar6[0x29] = uVar1;
        puVar6[0x2a] = uVar2;
        puVar6[0x2b] = uVar3;
        uVar1 = puVar17[0x2d];
        uVar2 = puVar17[0x2f];
        uVar3 = puVar17[0x2e];
        puVar6[0x2c] = puVar17[0x2c];
        puVar6[0x2d] = uVar1;
        puVar6[0x2e] = uVar3;
        puVar6[0x2f] = uVar2;
        iVar15 = *(int *)(param_4 + 4);
        if (iVar15 != 0) break;
LAB_002cbb48:
        iVar18 = iVar18 + 1;
        func_0x0084e5b0(uVar5,*(undefined4 *)(param_4 + 8),1,(ulong)puStack_98 & 0xffffffff);
        lVar19 = lVar19 + 4;
        if (param_2 == iVar18) goto LAB_002cbb74;
      }
      iVar4 = *(int *)(param_4 + 8);
      if ((uint)((*(int *)(param_4 + 0xc) - iVar15 >> 4) * -0x49249249) <=
          (uint)((iVar4 - iVar15 >> 4) * -0x49249249)) goto LAB_002cbb48;
      if (iVar4 != 0) {
        func_0x0071b098(iVar4,(ulong)puStack_98 & 0xffffffff,0x70);
      }
      iVar18 = iVar18 + 1;
      *(int *)(param_4 + 8) = iVar4 + 0x70;
      lVar19 = lVar19 + 4;
    } while (param_2 != iVar18);
  }
LAB_002cbb74:
  iVar18 = *(int *)(uStack_a8 + 0x28);
  func_0x0084cac0((ulong)auStack_14c & 0xffffffff,uVar5);
  func_0x0089bea0(iVar18 + 0x6c,(ulong)auStack_14c & 0xffffffff);
  if (iStack_148 != 0) {
    func_0x0071b0c8(iStack_148);
  }
  uStack_140 = 0;
  iStack_148 = 0;
  uStack_144 = 0;
  func_0x002ca838((ulong)auStack_13c & 0xffffffff,iStack_b0);
  uVar16 = func_0x008a0310(iStack_b0 + 0x44,(ulong)auStack_13c & 0xffffffff);
  func_0x0089bea0(uVar16,uVar5);
  if (0xf < uStack_124) {
    func_0x0071b0c8(uStack_138);
  }
  return;
}



// ===== function 0x2c7c00 =====

undefined1 FUN_002c7c00(long param_1,undefined4 param_2)

{
  ulong uVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 uVar6;
  undefined1 auStack_490 [64];
  undefined1 auStack_450 [1048];
  
  uVar1 = (ulong)auStack_450 & 0xffffffff;
  *(undefined1 *)(param_1 + 0x30) = 1;
  func_0x0071d708(uVar1);
  uVar2 = (ulong)auStack_490 & 0xffffffff;
  uVar4 = func_0x002d0098(param_1,(long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 8),uVar2);
  uVar3 = uRam0000000000e9ab88 /* 'source/online/svo/ms2actions.cpp' */;
  func_0x0071d718(uVar1,uRam0000000000e9ab88 /* 'source/online/svo/ms2actions.cpp' */,0x299,uRam0000000000e9ab8c /* 'location.gameMode' */,uVar4);
  iVar5 = FUN_002c20f8((long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 4));
  uVar4 = func_0x002d0098(param_1,(long)iVar5,uVar2);
  func_0x0071d718(uVar1,uVar3,0x29a,uRam0000000000e9ab90 /* 'location.vehicle' */,uVar4);
  uVar4 = func_0x002d0098(param_1,(long)*(int *)(ulong)*(uint *)(param_1 + 0x28),uVar2);
  func_0x0071d718(uVar1,uVar3,0x29b,uRam0000000000e9ab94 /* 'location.track' */,uVar4);
  uVar4 = func_0x002d0098(param_1,(long)*(int *)((ulong)*(uint *)(param_1 + 0x28) + 0xc),uVar2);
  func_0x0071d718(uVar1,uVar3,0x29c,uRam0000000000e9ab98 /* 'account' */,uVar4);
  uVar6 = func_0x002cf820(param_2,uRam0000000000e9ab9c /* 'ghost' */,uVar1);
  func_0x0071d728(uVar1);
  return uVar6;
}



// ===== function 0x2c8760 =====

uint FUN_002c8760(ulong param_1)

{
  ulong uVar1;
  ulong uVar2;
  char cVar10;
  undefined4 uVar5;
  ulong uVar3;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar4;
  uint uVar9;
  undefined4 uStack_470;
  undefined4 uStack_46c;
  int iStack_468;
  undefined1 auStack_460 [16];
  undefined1 auStack_450 [1048];
  
  uVar1 = (ulong)auStack_450 & 0xffffffff;
  func_0x0071d708(uVar1);
  cVar10 = FUN_002c8328(param_1 & 0xffffffff,uVar1);
  if (cVar10 != '\0') {
    uVar5 = func_0x002b6db0();
    uVar3 = func_0x002b1c30(uVar5);
    uVar2 = uVar3 & 0xffffffff;
    iVar6 = func_0x0021e838(uVar2);
    iVar7 = func_0x0021e838(uVar2);
    iVar8 = func_0x0021e838(uVar2);
    func_0x0027c1b8(uRam0000000000e9abf8 /* 'Posting ghost data : %s %s %s' */,iVar6 + 8,iVar7 + 0x48,iVar8 + 0x28);
    func_0x00bdf650((ulong)auStack_460 & 0xffffffff,uRam0000000000e9abe4,*(int *)(uVar3 + 4) + 0x40)
    ;
    func_0x0071d718(uVar1,uRam0000000000e9ab88 /* 'source/online/svo/ms2actions.cpp' */,0x368,uRam0000000000e9abfc /* 'ghostLength' */,
                    (ulong)auStack_460 & 0xffffffff);
    uStack_470 = uRam0000000000e9ac00 /* 'application/octet-stream' */;
    iStack_468 = *(int *)(uVar3 + 4) + 0x40;
    uStack_46c = (undefined4)uVar3;
    func_0x0027c1b8(uRam0000000000e9ac04 /* 'Size %d' */,*(int *)(uVar3 + 4) + 0x40);
    uVar5 = func_0x002cff08();
    uVar5 = func_0x00792338(uVar5);
    puVar4 = (uint *)func_0x00792378(uVar5);
    uVar9 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar4 + 0x14))
                      ((ulong)puVar4 & 0xffffffff,uRam0000000000e9ac08 /* 'finishGame' */,7,uVar1,&uStack_470,0,1);
    *(undefined1 *)(param_1 + 0x38) = 1;
    func_0x0071d728(auStack_450);
    return ((int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f ^ uVar9) >> 0x1f;
  }
  func_0x0071d728(auStack_450);
  return 0;
}



// ===== function 0x2c9408 =====

int FUN_002c9408(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  char cVar6;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = func_0x002d0748();
  if ((iVar1 == 1) && (*(char *)(param_1 + 0x38) == '\0')) {
    syscall(0);
    uVar2 = func_0x002b6db0();
    cVar6 = func_0x001f3d48(uVar2);
    if (cVar6 != '\0') {
      uVar2 = func_0x002b6db0();
      iVar3 = func_0x002b1c30(uVar2);
      if (iVar3 == 0) {
        func_0x0027c1b8(uRam0000000000e9ac50 /* 'Skipping ghost data post' */);
        func_0x002c89a0(param_1);
      }
      else {
        iVar4 = func_0x0021e838(iVar3);
        iVar5 = func_0x0021e838(iVar3);
        iVar3 = func_0x0021e838(iVar3);
        func_0x0027c1b8(uRam0000000000e9abf8 /* 'Posting ghost data : %s %s %s' */,iVar4 + 8,iVar5 + 0x48,iVar3 + 0x28);
        FUN_002c8760(param_1);
      }
    }
  }
  return iVar1;
}



// ===== function 0x29cdb0 =====

void FUN_0029cdb0(long param_1)

{
  int iVar1;
  
  func_0x0027c1b8(uRam0000000000e9a258 /* 'RetrieveGhostData' */);
  iVar1 = *(int *)(ulong)uRam0000000000e9a21c;
  if (iVar1 != 0) {
    func_0x002c1880(iVar1,0);
    func_0x002c1ac0(iVar1,uRam0000000000e9a25c /* 'Ghost retrieved' */);
    *(undefined1 *)(param_1 + 0x42) = 0;
  }
  return;
}



// ===== function 0x29c6f0 =====

void FUN_0029c6f0(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 undefined4 param_9)

{
  func_0x0027c1b8(uRam0000000000e9a1f8 /* 'RegisterGhostDownload' */);
  *(undefined8 *)(param_1 + 0x150) = param_4;
  *(undefined8 *)(param_1 + 0x158) = param_5;
  *(undefined8 *)(param_1 + 0x160) = param_6;
  *(undefined8 *)(param_1 + 0x168) = param_7;
  *(int *)(param_1 + 0x170) = (int)((ulong)param_8 >> 0x20);
  *(undefined4 *)(param_1 + 0x178) = param_9;
  *(int *)(param_1 + 0x17c) = (int)param_1 + 0x50;
  *(undefined4 *)(param_1 + 0x174) = param_9;
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x34);
  *(undefined1 *)(param_1 + 0x42) = 1;
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x5c);
  return;
}



// ===== function 0x2c9538 =====

undefined1 FUN_002c9538(ulong param_1)

{
  undefined4 uVar2;
  long lVar1;
  int iVar3;
  char cVar4;
  undefined1 uVar5;
  
  *(undefined1 *)(param_1 + 0x38) = 0;
  uVar2 = func_0x002b6db0();
  lVar1 = func_0x0027c1b8(uVar2);
  iVar3 = 0;
  if (*(int *)(lVar1 + 4) != 0) {
    iVar3 = *(int *)(lVar1 + 8) - *(int *)(lVar1 + 4) >> 2;
  }
  func_0x0027c1b8(uRam0000000000e9ac54 /* 'Ready to post %d stats' */,iVar3);
  uVar2 = func_0x002b6db0();
  iVar3 = func_0x002b1be0(uVar2);
  uVar5 = 0;
  if (iVar3 != 0) {
    uVar2 = func_0x002b6db0();
    cVar4 = func_0x002b1eb0(uVar2);
    uVar5 = 1;
    if (cVar4 == '\0') {
      func_0x0027c1b8(uRam0000000000e9ac58 /* 'No ghost check, posting immediate' */);
      uVar5 = func_0x002c89a0(param_1 & 0xffffffff);
      return uVar5;
    }
  }
  return uVar5;
}



