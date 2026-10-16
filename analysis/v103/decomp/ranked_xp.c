// ===== function 0x2788c8 =====

void FUN_002788c8(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar6;
  int iVar5;
  char *pcVar7;
  
  cVar6 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(ulong)
                                                  uRam0000000000e99694 + 0x364))
                    ((uint *)(ulong)*(uint *)(ulong)uRam0000000000e99694);
  uVar4 = uRam0000000000e99704 /* '\n\t--------------Ranked Game Stats Pre Race------------\n' */;
  if (cVar6 == '\0') {
    return;
  }
  func_0x0027c1b8(uRam0000000000e99704 /* '\n\t--------------Ranked Game Stats Pre Race------------\n' */);
  func_0x0027c1b8(uRam0000000000e99708 /* '\tXP\t\t\t\t\t\t= %d ' */,(long)(int)param_1[0xb]);
  uVar2 = uRam0000000000e996a4;
  pcVar7 = (char *)(ulong)uRam0000000000e996a0;
  if (*pcVar7 != '\0') {
    iVar5 = func_0x002b6f80(uRam0000000000e996a4,(long)(int)param_1[0xb]);
    func_0x0027c1b8(uRam0000000000e9970c /* '\tRank Level\t\t\t\t= %d ' */,(long)iVar5);
    func_0x0027c1b8(uRam0000000000e99710 /* '\tRanked Winning Streak\t= %d ' */,(long)(int)param_1[0x12]);
    func_0x0027c1b8(uRam0000000000e99714 /* '\tQuit Status\t\t\t\t= %d ' */,*(undefined1 *)(param_1 + 0x13));
    func_0x0027c1b8(uRam0000000000e99718 /* '\tRanked Quit Count\t    = %d ' */,(long)(int)param_1[0xc]);
    func_0x0027c1b8(uVar4);
    *(undefined1 *)((long)param_1 + 0x26) = 1;
    uVar1 = param_1[0xb];
    *(undefined1 *)(param_1 + 0x13) = 1;
    uVar4 = uRam0000000000e9971c /* 'xp of Player is set in NetObj = %d, level %d' */;
    *(uint *)((ulong)*(uint *)((ulong)*param_1 + 0x20) + 0x3c) = uVar1;
    func_0x0027c1b8(uVar4,(long)(int)uVar1);
    func_0x0027c1b8(uRam0000000000e99720 /* '--------------End of Stats Pre Race------------' */);
    return;
  }
  func_0x002b94c0(uRam0000000000e996a4);
  uVar3 = uRam0000000000e996a8;
  *pcVar7 = '\x01';
  func_0x0071b348(uVar3);
  iVar5 = func_0x002b6f80(uVar2,(long)(int)param_1[0xb]);
  func_0x0027c1b8(uRam0000000000e9970c /* '\tRank Level\t\t\t\t= %d ' */,(long)iVar5);
  func_0x0027c1b8(uRam0000000000e99710 /* '\tRanked Winning Streak\t= %d ' */,(long)(int)param_1[0x12]);
  func_0x0027c1b8(uRam0000000000e99714 /* '\tQuit Status\t\t\t\t= %d ' */,*(undefined1 *)(param_1 + 0x13));
  func_0x0027c1b8(uRam0000000000e99718 /* '\tRanked Quit Count\t    = %d ' */,(long)(int)param_1[0xc]);
  func_0x0027c1b8(uVar4);
  *(undefined1 *)((long)param_1 + 0x26) = 1;
  uVar1 = param_1[0xb];
  *(undefined1 *)(param_1 + 0x13) = 1;
  uVar4 = uRam0000000000e9971c /* 'xp of Player is set in NetObj = %d, level %d' */;
  *(uint *)((ulong)*(uint *)((ulong)*param_1 + 0x20) + 0x3c) = uVar1;
  func_0x0027c1b8(uVar4,(long)(int)uVar1);
  func_0x0027c1b8(uRam0000000000e99720 /* '--------------End of Stats Pre Race------------' */);
  return;
}



// ===== function 0x278b38 =====

void FUN_00278b38(ulong param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = param_1 + 0x24 & 0xffffffff;
  func_0x002ab530(uVar1,(long)*(char *)((ulong)*(uint *)((ulong)*(uint *)(param_1 + 4) + 0x14) + 2))
  ;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  *(undefined1 *)(param_1 + 0x4f) = 1;
  FUN_002788c8(param_1 & 0xffffffff);
  uVar2 = func_0x002ab868(uVar1);
  puVar3 = (uint *)(ulong)uRam0000000000e99694;
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar3 + 0x104))
            ((uint *)(ulong)*puVar3);
  *(undefined1 *)(param_1 + 0x26) = 1;
  func_0x0027c1b8(uRam0000000000e99724 /* 'PreRaceStatsUpdate performed' */);
  return;
}



// ===== function 0x278d88 =====

void FUN_00278d88(long param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar6;
  int iVar4;
  undefined4 uVar5;
  char *pcVar7;
  undefined1 auStack_50 [4];
  undefined4 uStack_4c;
  uint uStack_38;
  
  cVar6 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(ulong)
                                                  uRam0000000000e99694 + 0x364))
                    ((uint *)(ulong)*(uint *)(ulong)uRam0000000000e99694);
  uVar5 = uRam0000000000e99738 /* '\n--------------Ranked Game Quit Race Stats------------\n' */;
  if (cVar6 != '\0') {
    *(undefined1 *)(param_1 + 0x4e) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    func_0x0027c1b8(uVar5);
    uVar1 = param_1 + 0x24U & 0xffffffff;
    func_0x0027c1b8(uRam0000000000e99708 /* '\tXP\t\t\t\t\t\t= %d ' */,(long)*(int *)(param_1 + 0x2c));
    uVar2 = uRam0000000000e996a4;
    pcVar7 = (char *)(ulong)uRam0000000000e996a0;
    if (*pcVar7 == '\0') {
      func_0x002b94c0(uRam0000000000e996a4);
      uVar3 = uRam0000000000e996a8;
      *pcVar7 = '\x01';
      func_0x0071b348(uVar3);
      iVar4 = func_0x002b6f80(uVar2,(long)*(int *)(param_1 + 0x2c));
      func_0x0027c1b8(uRam0000000000e9970c /* '\tRank Level\t\t\t\t= %d ' */,(long)iVar4);
      func_0x0027c1b8(uRam0000000000e99710 /* '\tRanked Winning Streak\t= %d ' */,(long)*(int *)(param_1 + 0x48));
      func_0x0027c1b8(uRam0000000000e99714 /* '\tQuit Status\t\t\t\t= %d ' */,*(undefined1 *)(param_1 + 0x4c));
      func_0x0027c1b8(uRam0000000000e9973c /* '\tRanked Quit Count\t\t= %d' */,(long)*(int *)(param_1 + 0x30));
      func_0x0027c1b8(uVar5);
      func_0x002abaa8(uVar1);
      *(undefined1 *)(param_1 + 0x26) = 1;
    }
    else {
      iVar4 = func_0x002b6f80(uRam0000000000e996a4,(long)*(int *)(param_1 + 0x2c));
      func_0x0027c1b8(uRam0000000000e9970c /* '\tRank Level\t\t\t\t= %d ' */,(long)iVar4);
      func_0x0027c1b8(uRam0000000000e99710 /* '\tRanked Winning Streak\t= %d ' */,(long)*(int *)(param_1 + 0x48));
      func_0x0027c1b8(uRam0000000000e99714 /* '\tQuit Status\t\t\t\t= %d ' */,*(undefined1 *)(param_1 + 0x4c));
      func_0x0027c1b8(uRam0000000000e9973c /* '\tRanked Quit Count\t\t= %d' */,(long)*(int *)(param_1 + 0x30));
      func_0x0027c1b8(uVar5);
      func_0x002abaa8(uVar1);
      *(undefined1 *)(param_1 + 0x26) = 1;
    }
    uVar5 = func_0x002b6db0();
    uVar5 = func_0x002b1be0(uVar5);
    func_0x002b0700(uVar5,uRam0000000000e99740 /* 'score' */,(long)*(int *)(param_1 + 0x2c));
    uVar5 = func_0x002b6db0();
    func_0x0074a310((ulong)auStack_50 & 0xffffffff,uRam0000000000e99744 /* 'localQuit' */);
    func_0x002b1d28(uVar5,(ulong)auStack_50 & 0xffffffff);
    if (0xf < uStack_38) {
      func_0x0071b0c8(uStack_4c);
      return;
    }
  }
  return;
}



// ===== function 0x279040 =====

void FUN_00279040(ulong param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  
  func_0x002781b0(param_1 & 0xffffffff);
  *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
  *(undefined1 *)(param_1 + 0x4f) = 0;
  FUN_00278d88(param_1 & 0xffffffff);
  uVar1 = func_0x002ab868(param_1 + 0x24 & 0xffffffff);
  puVar2 = (uint *)(ulong)uRam0000000000e99694;
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar2 + 0x104))
            ((uint *)(ulong)*puVar2);
  uVar1 = uRam0000000000e99748 /* 'QuitRaceStatsUpdate performed' */;
  *(undefined1 *)(param_1 + 0x26) = 1;
  func_0x0027c1b8(uVar1);
  return;
}



// ===== function 0x2790f8 =====

void FUN_002790f8(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char cVar9;
  uint uVar5;
  int iVar6;
  ulong uVar4;
  int iVar7;
  undefined4 uVar8;
  ulong uVar10;
  uint uVar11;
  ulong uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  char *pcVar17;
  ulong uVar18;
  int iVar19;
  uint uVar20;
  uint uVar22;
  ulong uVar21;
  int iVar23;
  double dVar24;
  double dVar25;
  
  cVar9 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(ulong)
                                                  uRam0000000000e99694 + 0x364))
                    ((uint *)(ulong)*(uint *)(ulong)uRam0000000000e99694);
  if (cVar9 == '\0') {
    return;
  }
  if ((*(ushort *)((ulong)*(uint *)((ulong)*param_1 + 0x20) + 0x2c) & 0x10) == 0) {
    return;
  }
  func_0x0027c1b8(uRam0000000000e9978c /* '\n\n\t=============== PostRaceRankingUpdate ======================\n' */);
  *(undefined1 *)(param_1 + 0x13) = 0;
  uVar8 = uRam0000000000e99750 /* 'Ranked quit count decremented to %i' */;
  if (0 < (int)param_1[0xc]) {
    uVar13 = param_1[0xc] - 1;
    param_1[0xc] = uVar13;
    func_0x0027c1b8(uVar8,(long)(int)uVar13);
  }
  uVar13 = uRam0000000000e996a4;
  pcVar17 = (char *)(ulong)uRam0000000000e996a0;
  if (*pcVar17 == '\0') {
    func_0x002b94c0(uRam0000000000e996a4);
    uVar8 = uRam0000000000e996a8;
    *pcVar17 = '\x01';
    func_0x0071b348(uVar8);
  }
  uVar11 = param_1[0xb];
  uVar5 = func_0x002b6f80(uVar13,(long)(int)uVar11);
  iVar6 = func_0x002b6e98(uVar13,(long)(int)uVar5);
  uVar4 = func_0x00768b58();
  iVar7 = func_0x002acb00(uVar4 & 0xffffffff);
  func_0x0027c1b8(uRam0000000000e99754 /* 'I finished in position %d' */,(long)(iVar7 + 1));
  dVar25 = dRam0000000000e99790;
  uVar3 = uRam0000000000e996a4;
  if ((*(int *)(uVar4 + 4) == 0) ||
     (iVar16 = (*(int *)(uVar4 + 8) - *(int *)(uVar4 + 4) >> 3) * -0xf0f0f0f, iVar16 == 0)) {
    iVar14 = 0;
    func_0x0027c1b8(uRam0000000000e99764 /* 'XP BEFORE %d' */,(long)(int)param_1[0xb]);
    if (*pcVar17 == '\0') goto LAB_00279890;
LAB_002798b0:
    uVar20 = *(uint *)((ulong)uVar3 + 4);
    uVar4 = (ulong)(int)(uVar20 ^ 0x80000000);
    uVar18 = (ulong)(int)((uVar5 ^ 0x80000000) + 0x80000000 &
                          ~-(uint)((uVar5 ^ 0x80000000) < 0x80000000) ^ 0x80000000);
    uVar20 = (int)(dVar25 * *(double *)
                             ((((ulong)uVar20 + (uVar18 - uVar4 & -(ulong)(uVar18 < uVar4)) &
                               0xfffffff) * 0x10 + (ulong)*(uint *)((ulong)uVar3 + 0x38) &
                              0xffffffff) + 8)) + uVar11 + iVar14;
    func_0x0027c1b8(uRam0000000000e99768 /* '**** XP AFTER = %d ***' */,(long)(int)uVar20);
    if (*pcVar17 == '\0') goto LAB_00279a34;
  }
  else {
    iVar15 = 0;
    uVar18 = (ulong)uRam0000000000e996a4;
    iVar14 = 0;
    iVar19 = 0;
    iVar23 = 0;
    do {
      while( true ) {
        uVar20 = iVar23 + *(int *)(uVar4 + 4);
        if (*(char *)(ulong)uVar20 == '\0') break;
LAB_002793a8:
        iVar19 = iVar19 + 1;
        iVar23 = iVar23 + 0x88;
        if (iVar19 == iVar16) goto LAB_002794a4;
      }
      uVar21 = (ulong)(uVar20 + 0x14);
      uVar22 = uVar5 - *(int *)((char *)(ulong)uVar20 + 0x10);
      if (*(uint *)(uVar21 + 0x18) < 0x10) {
        func_0x0027c1b8(uRam0000000000e99758 /* '%s: relLevel %d, remotePos %d' */,uVar20 + 0x18,(long)(int)uVar22,(long)iVar19);
      }
      else {
        func_0x0027c1b8(uRam0000000000e99758 /* '%s: relLevel %d, remotePos %d' */,*(undefined4 *)(uVar21 + 4),(long)(int)uVar22,
                        (long)iVar19);
      }
      if (iVar7 <= iVar19) {
        uVar1 = *(uint *)(uVar18 + 8);
        uVar10 = (ulong)(int)(*(uint *)(uVar18 + 0xc) ^ 0x80000000);
        uVar12 = (ulong)(int)(uVar1 + ((uVar22 ^ 0x80000000) - (uVar1 ^ 0x80000000) &
                                      ~-(uint)((uVar22 ^ 0x80000000) < (uVar1 ^ 0x80000000))) ^
                             0x80000000);
        iVar2 = *(int *)((((ulong)*(uint *)(uVar18 + 0xc) +
                          (uVar12 - uVar10 & -(ulong)(uVar12 < uVar10))) - (ulong)uVar1 & 0x1fffffff
                         ) * 8 + (ulong)*(uint *)(uVar18 + 0x48) & 0xffffffff);
        if (*(uint *)(uVar21 + 0x18) < 0x10) {
          iVar14 = iVar14 + iVar2;
          func_0x0027c1b8(uRam0000000000e99760 /* 'I beat %s   = Win point %d' */,uVar20 + 0x18,(long)iVar2);
        }
        else {
          iVar14 = iVar14 + iVar2;
          func_0x0027c1b8(uRam0000000000e99760 /* 'I beat %s   = Win point %d' */,*(undefined4 *)(uVar21 + 4),(long)iVar2);
        }
        goto LAB_002793a8;
      }
      uVar1 = *(uint *)(uVar18 + 8);
      uVar12 = (ulong)(int)(*(uint *)(uVar18 + 0xc) ^ 0x80000000);
      uVar10 = (ulong)(int)(uVar1 + ((uVar22 ^ 0x80000000) - (uVar1 ^ 0x80000000) &
                                    ~-(uint)((uVar22 ^ 0x80000000) < (uVar1 ^ 0x80000000))) ^
                           0x80000000);
      iVar2 = *(int *)(((((ulong)*(uint *)(uVar18 + 0xc) +
                         (uVar10 - uVar12 & -(ulong)(uVar10 < uVar12))) - (ulong)uVar1 & 0x1fffffff)
                        * 8 + (ulong)*(uint *)(uVar18 + 0x48) & 0xffffffff) + 4);
      if (0xf < *(uint *)(uVar21 + 0x18)) {
        iVar15 = iVar15 + iVar2;
        func_0x0027c1b8(uRam0000000000e9975c /* '%s beat me = lossPoints %d' */,*(undefined4 *)(uVar21 + 4),(long)iVar2);
        goto LAB_002793a8;
      }
      iVar19 = iVar19 + 1;
      iVar15 = iVar15 + iVar2;
      func_0x0027c1b8(uRam0000000000e9975c /* '%s beat me = lossPoints %d' */,uVar20 + 0x18,(long)iVar2);
      iVar23 = iVar23 + 0x88;
    } while (iVar19 != iVar16);
LAB_002794a4:
    dVar25 = (double)(long)iVar15;
    func_0x0027c1b8(uRam0000000000e99764 /* 'XP BEFORE %d' */,(long)(int)param_1[0xb]);
    if (*pcVar17 == '\0') {
LAB_00279890:
      func_0x002b94c0(uVar13);
      uVar8 = uRam0000000000e996a8;
      *pcVar17 = '\x01';
      func_0x0071b348(uVar8);
      goto LAB_002798b0;
    }
    uVar4 = (ulong)(int)(*(uint *)(uVar18 + 4) ^ 0x80000000);
    uVar21 = (ulong)(int)((uVar5 ^ 0x80000000) + 0x80000000 &
                          ~-(uint)((uVar5 ^ 0x80000000) < 0x80000000) ^ 0x80000000);
    uVar20 = (int)(dVar25 * *(double *)
                             ((((ulong)*(uint *)(uVar18 + 4) +
                                (uVar21 - uVar4 & -(ulong)(uVar21 < uVar4)) & 0xfffffff) * 0x10 +
                               (ulong)*(uint *)(uVar18 + 0x38) & 0xffffffff) + 8)) + uVar11 + iVar14
    ;
    func_0x0027c1b8(uRam0000000000e99768 /* '**** XP AFTER = %d ***' */,(long)(int)uVar20);
    if (*pcVar17 != '\0') {
      uVar4 = (ulong)(int)(*(uint *)(uVar18 + 4) ^ 0x80000000);
      dVar24 = *(double *)
                ((((ulong)*(uint *)(uVar18 + 4) + (uVar21 - uVar4 & -(ulong)(uVar21 < uVar4)) &
                  0xfffffff) * 0x10 + (ulong)*(uint *)(uVar18 + 0x38) & 0xffffffff) + 8);
      goto LAB_002795ac;
    }
LAB_00279a34:
    func_0x002b94c0(uVar13);
    uVar8 = uRam0000000000e996a8;
    *pcVar17 = '\x01';
    func_0x0071b348(uVar8);
  }
  uVar22 = *(uint *)((ulong)uVar3 + 4);
  uVar18 = (ulong)(int)(uVar22 ^ 0x80000000);
  uVar4 = (ulong)(int)((uVar5 ^ 0x80000000) + 0x80000000 &
                       ~-(uint)((uVar5 ^ 0x80000000) < 0x80000000) ^ 0x80000000);
  dVar24 = *(double *)
            ((((ulong)uVar22 + (uVar4 - uVar18 & -(ulong)(uVar4 < uVar18)) & 0xfffffff) * 0x10 +
              (ulong)*(uint *)((ulong)uVar3 + 0x38) & 0xffffffff) + 8);
LAB_002795ac:
  uVar18 = (ulong)uVar3;
  func_0x0027c1b8(dVar25 * dVar24,uRam0000000000e9976c /* 'LOST = %f' */,dVar25 * dVar24);
  func_0x0027c1b8(uRam0000000000e99770 /* 'WIN  = %d' */,(long)iVar14);
  uVar4 = (ulong)uRam0000000000e99698;
  if ((*(int *)(uVar4 + 0x88) != 0) && ((int)uVar20 < (int)uVar11)) {
    func_0x0027c1b8(uRam0000000000e99774 /* 'XP not decreased due to recent rank promotion %d' */,(long)(int)uVar11);
    uVar20 = uVar11;
  }
  if (*pcVar17 == '\0') {
    func_0x002b94c0(uVar13);
    uVar8 = uRam0000000000e996a8;
    *pcVar17 = '\x01';
    func_0x0071b348(uVar8);
  }
  uVar10 = (ulong)*(uint *)(uVar18 + 4);
  uVar12 = (ulong)(int)(*(uint *)(uVar18 + 4) ^ 0x80000000);
  uVar21 = (ulong)*(uint *)(uVar18 + 0x38);
  if ((int)uVar20 <
      *(int *)((uVar10 + (-uVar12 - 0x80000000 & -(ulong)(0xffffffff80000000 < uVar12)) & 0xfffffff)
               * 0x10 + uVar21 & 0xffffffff)) {
    if (*pcVar17 == '\0') {
      func_0x002b94c0(uVar13);
      uVar8 = uRam0000000000e996a8;
      *pcVar17 = '\x01';
      func_0x0071b348(uVar8);
      uVar10 = (ulong)*(uint *)(uVar18 + 4);
      uVar21 = (ulong)*(uint *)(uVar18 + 0x38);
    }
    uVar12 = (ulong)(int)((uint)uVar10 ^ 0x80000000);
    uVar20 = *(uint *)((uVar10 + (-uVar12 - 0x80000000 & -(ulong)(0xffffffff80000000 < uVar12)) &
                       0xfffffff) * 0x10 + uVar21 & 0xffffffff);
  }
  if (*pcVar17 == '\0') {
    func_0x002b94c0(uVar13);
    uVar8 = uRam0000000000e996a8;
    *pcVar17 = '\x01';
    func_0x0071b348(uVar8);
  }
  if (((int)*(uint *)(uVar18 + 0x20) < (int)uVar20) &&
     (uVar20 = *(uint *)(uVar18 + 0x20), *pcVar17 == '\0')) {
    func_0x002b94c0(uVar13);
    uVar8 = uRam0000000000e996a8;
    *pcVar17 = '\x01';
    func_0x0071b348(uVar8);
    uVar20 = *(uint *)(uVar18 + 0x20);
  }
  param_1[0xb] = uVar20;
  if (*pcVar17 == '\0') {
    func_0x002b94c0(uVar13);
    uVar8 = uRam0000000000e996a8;
    *pcVar17 = '\x01';
    func_0x0071b348(uVar8);
  }
  uVar11 = *(uint *)(uVar18 + 0x20);
  if ((int)uVar11 < (int)uVar20) {
    if (*pcVar17 == '\0') {
      func_0x002b94c0(uVar13);
      uVar8 = uRam0000000000e996a8;
      *pcVar17 = '\x01';
      func_0x0071b348(uVar8);
      uVar11 = *(uint *)(uVar18 + 0x20);
    }
    param_1[0xb] = uVar11;
  }
  uVar8 = uRam0000000000e99778 /* '\n\t\t--------------Ranked Game Stats Post Race------------\n' */;
  func_0x0027c1b8(uRam0000000000e99778 /* '\n\t\t--------------Ranked Game Stats Post Race------------\n' */);
  func_0x0027c1b8(uRam0000000000e99708 /* '\tXP\t\t\t\t\t\t= %d ' */,(long)(int)param_1[0xb]);
  iVar7 = func_0x002b6f80(uVar13,(long)(int)param_1[0xb]);
  func_0x0027c1b8(uRam0000000000e9970c /* '\tRank Level\t\t\t\t= %d ' */,(long)iVar7);
  func_0x0027c1b8(uRam0000000000e99710 /* '\tRanked Winning Streak\t= %d ' */,(long)(int)param_1[0x12]);
  func_0x0027c1b8(uRam0000000000e99714 /* '\tQuit Status\t\t\t\t= %d ' */,*(undefined1 *)(param_1 + 0x13));
  func_0x0027c1b8(uRam0000000000e9977c /* '\tRanked Quit Count\t\t= %d ' */,(long)(int)param_1[0xc]);
  func_0x0027c1b8(uVar8);
  *(undefined1 *)((long)param_1 + 0x26) = 1;
  uVar8 = func_0x002b6db0();
  uVar8 = func_0x002b1be0(uVar8);
  func_0x002b0700(uVar8,uRam0000000000e99740 /* 'score' */,(long)(int)uVar20);
  func_0x0027c1b8(uRam0000000000e99780);
  iVar7 = func_0x002b6f80(uVar13,(long)(int)uVar20);
  iVar7 = func_0x002b6e98(uVar13,(long)iVar7);
  uVar8 = uRam0000000000e99784 /* 'Immunity count decremented, immune for %u more races' */;
  if (*(int *)(uVar4 + 0x88) != 0) {
    iVar16 = *(int *)(uVar4 + 0x88) + -1;
    *(int *)(uVar4 + 0x88) = iVar16;
    func_0x0027c1b8(uVar8,iVar16);
  }
  uVar8 = uRam0000000000e99788 /* 'Ranked up baby! Immune for 3 races' */;
  if (iVar6 < iVar7) {
    *(undefined4 *)(uVar4 + 0x88) = 3;
    func_0x0027c1b8(uVar8);
  }
  return;
}



// ===== function 0x33730 =====

undefined4 FUN_00033730(undefined4 param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  char *pcVar4;
  int aiStack_30 [4];
  
  aiStack_30[0] = 1;
  cVar3 = func_0x00244660(*(undefined4 *)(param_2 + 0xdad0),uRam0000000000e91da8 /* 'Online.ranked.xp' */,aiStack_30,1);
  uVar1 = uRam0000000000e90374;
  if (cVar3 != '\0') {
    pcVar4 = (char *)(ulong)uRam0000000000e90370;
    if (*pcVar4 != '\0') {
      func_0x002baf78(param_1,uRam0000000000e90374,(long)aiStack_30[0]);
      return param_1;
    }
    func_0x002b94c0(uRam0000000000e90374);
    uVar2 = uRam0000000000e90378;
    *pcVar4 = '\x01';
    func_0x0071b348(uVar2);
    func_0x002baf78(param_1,uVar1,(long)aiStack_30[0],1,0);
    return param_1;
  }
  pcVar4 = (char *)(ulong)uRam0000000000e90370;
  if (*pcVar4 != '\0') {
    func_0x002baf78(param_1,uRam0000000000e90374);
    return param_1;
  }
  func_0x002b94c0(uRam0000000000e90374,0,1,1,0);
  uVar2 = uRam0000000000e90378;
  *pcVar4 = '\x01';
  func_0x0071b348(uVar2);
  func_0x002baf78(param_1,uVar1,1,1,0);
  return param_1;
}



// ===== function 0x34fb0 =====

void FUN_00034fb0(long param_1)

{
  undefined4 uVar1;
  char cVar4;
  undefined4 uVar2;
  int iVar3;
  char *pcVar5;
  uint *puVar6;
  undefined8 uVar7;
  
  cVar4 = func_0x001cd2b8(*(undefined4 *)
                           (((ulong)*(uint *)(param_1 + 0x60) & 0x3fffffff) * 4 +
                            (ulong)*(uint *)(param_1 + 0x5c) & 0xffffffff));
  uVar1 = uRam0000000000e90374;
  if (cVar4 == '\0') {
    pcVar5 = (char *)(ulong)uRam0000000000e90370;
    if (*pcVar5 == '\0') {
      func_0x002b94c0(uRam0000000000e90374);
      uVar2 = uRam0000000000e90378;
      *pcVar5 = '\x01';
      func_0x0071b348(uVar2);
      puVar6 = (uint *)(ulong)uRam0000000000e8fa0c;
      uVar2 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar6 + 0x670))
                        ((uint *)(ulong)*puVar6);
      iVar3 = func_0x002ab928(uVar2);
    }
    else {
      puVar6 = (uint *)(ulong)uRam0000000000e8fa0c;
      uVar2 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar6 + 0x670))
                        ((uint *)(ulong)*puVar6);
      iVar3 = func_0x002ab928(uVar2);
    }
    iVar3 = func_0x002b6e98(uVar1,(long)iVar3);
    uVar7 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar6 + 0x970))
                      ((uint *)(ulong)*puVar6);
    func_0x0027c1b8(uRam0000000000e91dc4 /* 'Initialising Players Rank Progress Bar %f, %d' */,uVar7,(long)iVar3);
    uVar1 = *(undefined4 *)
             (((ulong)*(uint *)(param_1 + 0x60) & 0x3fffffff) * 4 + (ulong)*(uint *)(param_1 + 0x5c)
             & 0xffffffff);
    (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar6 + 0x970))
              ((uint *)(ulong)*puVar6);
    func_0x001cd2a0(uVar1);
  }
  return;
}



// ===== function 0x2c99b8 =====

undefined8 FUN_002c99b8(ulong param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  long lVar15;
  undefined4 uVar17;
  int iVar18;
  long lVar16;
  undefined1 uVar19;
  uint uVar20;
  uint *puVar21;
  undefined1 *puVar22;
  uint uVar23;
  uint *puVar24;
  int iVar25;
  undefined8 in_LR;
  uint uStack_400;
  undefined1 auStack_3fc [48];
  undefined1 uStack_3cc;
  undefined4 uStack_3c8;
  int iStack_3c4;
  undefined4 uStack_3bc;
  undefined4 uStack_3b8;
  undefined4 uStack_3b4;
  undefined1 auStack_3b0 [808];
  
  lVar15 = func_0x0071d738();
  uVar17 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar15 + 0x1c))(param_2);
  iVar18 = func_0x0071b2d8(uVar17,uRam0000000000e9aba4 /* 'beaten_times' */);
  if (iVar18 == 0) {
    uVar6 = (ulong)auStack_3b0 & 0xffffffff;
    uVar7 = param_1 & 0xffffffff;
    func_0x0071b038(uVar6,0,800);
    lVar15 = func_0x0071d738();
    uVar10 = uRam0000000000e9ac88 /* 'time' */;
    iVar18 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar15 + 0x70))
                       (param_2,uRam0000000000e9ac88 /* 'time' */,uVar6,200);
    uVar14 = uRam0000000000e9ac98 /* 'vehicle' */;
    uVar13 = uRam0000000000e9ac94 /* 'track' */;
    uVar12 = uRam0000000000e9ac90 /* 'oldTime' */;
    uVar11 = uRam0000000000e9ac8c /* 'accountName' */;
    uVar17 = uRam0000000000e9ab98 /* 'account' */;
    if (0 < iVar18) {
      iVar25 = 0;
      lVar15 = 0;
      puVar8 = (undefined1 *)((ulong)auStack_3fc & 0xffffffff);
      do {
        while( true ) {
          lVar16 = func_0x0071d738();
          puVar9 = (undefined4 *)((ulong)(auStack_3b0 + lVar15) & 0xffffffff);
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar16 + 100))
                    (*puVar9,uVar11,(ulong)&uStack_400 & 0xffffffff);
          puVar22 = (undefined1 *)(ulong)uStack_400;
          uVar19 = puVar22[1];
          uVar1 = puVar22[2];
          uVar2 = puVar22[3];
          *puVar8 = *puVar22;
          puVar8[1] = uVar19;
          puVar8[2] = uVar1;
          puVar8[3] = uVar2;
          uVar19 = puVar22[5];
          uVar1 = puVar22[6];
          uVar2 = puVar22[7];
          puVar8[4] = puVar22[4];
          puVar8[5] = uVar19;
          puVar8[6] = uVar1;
          puVar8[7] = uVar2;
          uVar19 = puVar22[9];
          uVar1 = puVar22[10];
          uVar2 = puVar22[0xb];
          puVar8[8] = puVar22[8];
          puVar8[9] = uVar19;
          puVar8[10] = uVar1;
          puVar8[0xb] = uVar2;
          uVar19 = puVar22[0xd];
          uVar1 = puVar22[0xe];
          uVar2 = puVar22[0xf];
          puVar8[0xc] = puVar22[0xc];
          puVar8[0xd] = uVar19;
          puVar8[0xe] = uVar1;
          puVar8[0xf] = uVar2;
          uVar19 = puVar22[0x11];
          uVar1 = puVar22[0x12];
          uVar2 = puVar22[0x13];
          puVar8[0x10] = puVar22[0x10];
          puVar8[0x11] = uVar19;
          puVar8[0x12] = uVar1;
          puVar8[0x13] = uVar2;
          uVar19 = puVar22[0x15];
          uVar1 = puVar22[0x16];
          uVar2 = puVar22[0x17];
          puVar8[0x14] = puVar22[0x14];
          puVar8[0x15] = uVar19;
          puVar8[0x16] = uVar1;
          puVar8[0x17] = uVar2;
          uVar19 = puVar22[0x19];
          uVar1 = puVar22[0x1a];
          uVar2 = puVar22[0x1b];
          puVar8[0x18] = puVar22[0x18];
          puVar8[0x19] = uVar19;
          puVar8[0x1a] = uVar1;
          puVar8[0x1b] = uVar2;
          uVar19 = puVar22[0x1d];
          uVar1 = puVar22[0x1e];
          uVar2 = puVar22[0x1f];
          puVar8[0x1c] = puVar22[0x1c];
          puVar8[0x1d] = uVar19;
          puVar8[0x1e] = uVar1;
          puVar8[0x1f] = uVar2;
          uVar19 = puVar22[0x23];
          uVar1 = puVar22[0x21];
          uVar2 = puVar22[0x22];
          puVar8[0x20] = puVar22[0x20];
          puVar8[0x21] = uVar1;
          puVar8[0x22] = uVar2;
          puVar8[0x23] = uVar19;
          uVar19 = puVar22[0x25];
          uVar1 = puVar22[0x26];
          uVar2 = puVar22[0x27];
          puVar8[0x24] = puVar22[0x24];
          puVar8[0x25] = uVar19;
          puVar8[0x26] = uVar1;
          puVar8[0x27] = uVar2;
          uVar19 = puVar22[0x2b];
          uVar1 = puVar22[0x28];
          uVar2 = puVar22[0x29];
          puVar8[0x2a] = puVar22[0x2a];
          puVar8[0x2b] = uVar19;
          puVar8[0x28] = uVar1;
          puVar8[0x29] = uVar2;
          uVar19 = puVar22[0x2f];
          uVar1 = puVar22[0x2c];
          uVar2 = puVar22[0x2e];
          uVar3 = *puVar9;
          puVar8[0x2d] = puVar22[0x2d];
          puVar8[0x2c] = uVar1;
          puVar8[0x2e] = uVar2;
          puVar8[0x2f] = uVar19;
          uStack_3cc = 0;
          uStack_3bc = func_0x002d04a0(uVar7,uVar3,uVar17);
          uStack_3b8 = func_0x002d04a0(uVar7,*puVar9,uVar10);
          uStack_3b4 = func_0x002d04a0(uVar7,*puVar9,uVar12);
          uStack_3c8 = func_0x002d04a0(uVar7,*puVar9,uVar13);
          iStack_3c4 = func_0x002d04a0(uVar7,*puVar9,uVar14);
          iVar4 = *(int *)(param_1 + 0x2c);
          iStack_3c4 = iStack_3c4 + -1;
          if (iVar4 != 0) break;
          func_0x0089cdf8(param_1 + 0x28 & 0xffffffff,*(undefined4 *)(param_1 + 0x30),1,
                          (ulong)auStack_3fc & 0xffffffff);
LAB_002c9e08:
          iVar25 = iVar25 + 1;
          lVar15 = lVar15 + 4;
          if (iVar18 == iVar25) goto LAB_002c9e18;
        }
        iVar5 = *(int *)(param_1 + 0x30);
        if ((uint)((*(int *)(param_1 + 0x34) - iVar4 >> 2) * 0x286bca1b) <=
            (uint)((iVar5 - iVar4 >> 2) * 0x286bca1b)) {
          func_0x0089cdf8(param_1 + 0x28 & 0xffffffff,iVar5,1,(ulong)auStack_3fc & 0xffffffff);
          goto LAB_002c9e08;
        }
        if (iVar5 != 0) {
          func_0x0071b098(iVar5,puVar8,0x4c);
        }
        iVar25 = iVar25 + 1;
        *(int *)(param_1 + 0x30) = iVar5 + 0x4c;
        lVar15 = lVar15 + 4;
      } while (iVar18 != iVar25);
    }
LAB_002c9e18:
    uVar20 = 1;
    if (*(int *)(param_1 + 0x2c) != 0) {
      uVar23 = (*(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x2c) >> 2) * 0x286bca1b;
      uVar20 = (int)uVar23 >> 0x1f;
      uVar20 = ((uVar20 ^ uVar23) - uVar20) - 1 >> 0x1f;
    }
    puVar24 = (uint *)(ulong)uRam0000000000e9ab84;
    puVar21 = (uint *)(ulong)*puVar24;
    (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar21 + 0xdc0))(puVar21,uVar20 ^ 1);
    puVar21 = (uint *)(ulong)*puVar24;
    uVar19 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar21 + 0xdc4))(puVar21);
    func_0x0027c1b8(uRam0000000000e9ac9c /* 'Display announcements is %d' */,uVar19);
    func_0x002d0358(uVar7,0);
  }
  return in_LR;
}



