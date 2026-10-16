// ===== function 0x2c2198 =====

ulong FUN_002c2198(void)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar4 = (ulong)uRam0000000000e9aaa0 + 0x5030;
  uVar1 = uVar4 & 0xffffffff;
  uVar3 = 0;
  if (*(char *)((ulong)uRam0000000000e9aaa0 + 0x5030) != '\0') {
    uVar2 = func_0x0071b078(uVar1);
    func_0x0027c1b8(uRam0000000000e9aaa8 /* 'cSVO::GetAnnouncementText: Address = 0x%08x -- Size = %d' */,uVar1,uVar2);
    uVar3 = uVar4;
  }
  return uVar3 & 0xffffffff;
}



// ===== function 0x2c2440 =====

void FUN_002c2440(undefined8 param_1,int param_2)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  
  if (param_2 != 0) {
    iVar2 = func_0x0071b078(param_2);
    if (iVar2 < 0x400) {
      func_0x0027c1b8(uRam0000000000e9aad0 /* 'cSVO::SetAnnouncementText: New Announcement Text fits = 0x%08x -- Size = %d' */,param_2,(long)iVar2);
      uVar4 = (ulong)uRam0000000000e9aaa0;
      uVar1 = uVar4 + 0x5030 & 0xffffffff;
      func_0x0071bac8(uVar1,param_2,iVar2);
      *(undefined1 *)((long)iVar2 + uVar4 + 0x5030) = 0;
      uVar3 = func_0x0071b078(uVar1);
      func_0x0027c1b8(uRam0000000000e9aad8 /* 'cSVO::SetAnnouncementText: AnnouncementText Address = 0x%08x -- Size = %d' */,uVar1,uVar3);
      return;
    }
    func_0x0027c1b8(uRam0000000000e9aad4 /* 'cSVO::SetAnnouncementText: Cut Buffer Down to = 0x%08x -- Size = %d' */,param_2,0x3ff);
    uVar4 = (ulong)uRam0000000000e9aaa0;
    uVar1 = uVar4 + 0x5030 & 0xffffffff;
    func_0x0071bac8(uVar1,param_2,0x3ff);
    *(undefined1 *)(uVar4 + 0x542f) = 0;
    uVar3 = func_0x0071b078(uVar1);
    func_0x0027c1b8(uRam0000000000e9aad8 /* 'cSVO::SetAnnouncementText: AnnouncementText Address = 0x%08x -- Size = %d' */,uVar1,uVar3);
  }
  return;
}



// ===== function 0x2c9628 =====

undefined8 FUN_002c9628(ulong param_1,undefined4 param_2)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  undefined8 in_LR;
  
  lVar2 = func_0x0071d738();
  uVar3 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar2 + 0x1c))(param_2);
  iVar4 = func_0x0071b2d8(uVar3,uRam0000000000e9ac5c /* 'AnnouncementTxt' */);
  if (iVar4 != 0) {
    return in_LR;
  }
  lVar2 = func_0x0071d738();
  uVar3 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar2 + 0x68))(param_2,uRam0000000000e9ac60);
  lVar2 = func_0x0071d738();
  iVar4 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)(lVar2 + 0xc))(uVar3);
  *(int *)(param_1 + 0x28) = iVar4;
  if (iVar4 == 0) {
    uVar1 = *(uint *)(ulong)uRam0000000000e9ab84;
  }
  else {
    puVar6 = (uint *)(ulong)uRam0000000000e9ab84;
    puVar5 = (uint *)(ulong)*puVar6;
    (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar5 + 0xdb8))(puVar5,iVar4);
    uVar1 = *puVar6;
  }
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)uVar1 + 0xdc0))
            ((uint *)(ulong)uVar1,iVar4 != 0);
  func_0x002d0358(param_1 & 0xffffffff,0);
  return in_LR;
}



// ===== function 0x2ca948 =====

undefined1 FUN_002ca948(undefined4 param_1,undefined4 param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  uint *puVar6;
  undefined1 auStack_470 [4];
  undefined1 auStack_46c [4];
  uint auStack_468 [4];
  undefined4 uStack_458;
  uint uStack_454;
  undefined1 auStack_450 [1048];
  
  uVar1 = (ulong)auStack_450 & 0xffffffff;
  func_0x0071d708(uVar1);
  puVar6 = (uint *)(ulong)uRam0000000000e9ab84;
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar6 + 0x9c0))
            (auStack_46c,(uint *)(ulong)*puVar6);
  uVar2 = uRam0000000000e9ab88 /* 'source/online/svo/ms2actions.cpp' */;
  if (uStack_454 < 0x10) {
    func_0x0071d718(auStack_450,uRam0000000000e9ab88 /* 'source/online/svo/ms2actions.cpp' */,0xed,uRam0000000000e9aca4 /* 'country' */,
                    (ulong)auStack_468 & 0xffffffff);
    if (0xf < uStack_454) goto LAB_002cab58;
  }
  else {
    func_0x0071d718(uVar1,uRam0000000000e9ab88 /* 'source/online/svo/ms2actions.cpp' */,0xed,uRam0000000000e9aca4 /* 'country' */,auStack_468[0]);
    if (uStack_454 < 0x10) {
      auStack_468[0] = auStack_468[0] & 0xffffff;
      uStack_454 = 0xf;
      uStack_458 = 0;
      iVar3 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar6 + 0x9c4))();
      uVar4 = func_0x002d0098(param_1,(long)iVar3,auStack_470);
      func_0x0071d718(uVar1,uVar2,0xee,uRam0000000000e9aca8 /* 'languageCode' */,uVar4);
      goto LAB_002cab04;
    }
LAB_002cab58:
    func_0x0071b0c8(auStack_468[0]);
  }
  auStack_468[0] = auStack_468[0] & 0xffffff;
  uStack_454 = 0xf;
  uStack_458 = 0;
  iVar3 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar6 + 0x9c4))();
  uVar4 = func_0x002d0098(param_1,(long)iVar3,auStack_470);
  func_0x0071d718((ulong)auStack_450 & 0xffffffff,uVar2,0xee,uRam0000000000e9aca8 /* 'languageCode' */,uVar4);
LAB_002cab04:
  uVar5 = func_0x002cf820(param_2,uRam0000000000e9acc0 /* 'getAnnouncement' */,(ulong)auStack_450 & 0xffffffff);
  func_0x0071d728(auStack_450);
  return uVar5;
}



// ===== function 0x2d1a88 =====

void FUN_002d1a88(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar7;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  uint uVar15;
  int iVar18;
  long lVar16;
  ulong uVar17;
  ulong uVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  ulong uVar23;
  uint uVar24;
  
  *param_1 = uRam0000000000e9aee8;
  puVar2 = (undefined4 *)func_0x0071b0b8(0x28);
  func_0x002d0568((ulong)puVar2 & 0xffffffff,uRam0000000000e9aeec /* 'URL_List' */);
  *puVar2 = uRam0000000000e9aef0;
  param_1[1] = (int)puVar2;
  piVar3 = (int *)func_0x0071b0b8(0x2c);
  func_0x002d0568((ulong)piVar3 & 0xffffffff,uRam0000000000e9aef4 /* 'login' */);
  iVar18 = iRam0000000000e9aef8 + 0x44;
  *piVar3 = iRam0000000000e9aef8;
  piVar3[10] = iVar18;
  param_1[2] = (int)piVar3;
  puVar2 = (undefined4 *)func_0x0071b0b8(0x2c);
  func_0x002d0568((ulong)puVar2 & 0xffffffff,uRam0000000000e9aefc /* 'region' */);
  *puVar2 = uRam0000000000e9af00;
  puVar2[10] = 0;
  param_1[3] = (int)puVar2;
  puVar2 = (undefined4 *)func_0x0071b0b8(0x30);
  func_0x002d0568((ulong)puVar2 & 0xffffffff,uRam0000000000e9af04 /* 'eula' */);
  uVar7 = uRam0000000000e9af08;
  *(undefined1 *)(puVar2 + 0xb) = 0;
  *puVar2 = uVar7;
  puVar2[10] = 0;
  param_1[4] = (int)puVar2;
  puVar2 = (undefined4 *)func_0x0071b0b8(0x28);
  func_0x002d0568((ulong)puVar2 & 0xffffffff,uRam0000000000e9af0c /* 'acceptEula' */);
  *puVar2 = uRam0000000000e9af10;
  param_1[5] = (int)puVar2;
  puVar2 = (undefined4 *)func_0x0071b0b8(0x2c);
  func_0x002d0568((ulong)puVar2 & 0xffffffff,uRam0000000000e9af14 /* 'AnnouncementTxt' */);
  uVar7 = uRam0000000000e9af18;
  puVar2[10] = 0;
  *puVar2 = uVar7;
  param_1[6] = (int)puVar2;
  puVar2 = (undefined4 *)func_0x0071b0b8(0x3c);
  func_0x002d0568((ulong)puVar2 & 0xffffffff,uRam0000000000e9af1c /* 'poststats' */);
  uVar7 = uRam0000000000e9aec0;
  *puVar2 = uRam0000000000e9af20;
  puVar2[10] = uVar7;
  *(undefined1 *)(puVar2 + 0xe) = 0;
  param_1[7] = (int)puVar2;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  uVar7 = func_0x0071b0b8(0x34);
  func_0x002c9900(uVar7);
  param_1[8] = uVar7;
  uVar7 = func_0x0071b0b8(0x58);
  func_0x002cdf50(uVar7);
  param_1[9] = uVar7;
  puVar2 = (undefined4 *)func_0x0071b0b8(0x38);
  func_0x002d0568((ulong)puVar2 & 0xffffffff,uRam0000000000e9af24 /* 'beaten_times' */);
  *puVar2 = uRam0000000000e9af28;
  param_1[10] = (int)puVar2;
  puVar2[0xd] = 0;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0;
  uVar7 = func_0x0071b0b8(0x2c);
  func_0x002c7f10(uVar7);
  param_1[0xb] = uVar7;
  func_0x002c7980((ulong)(param_1 + 0xc) & 0xffffffff);
  *(undefined1 *)((long)param_1 + 0x79) = 0;
  uVar5 = -(long)param_1 - 0x7aU & 0xf;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  *(undefined1 *)(param_1 + 0x1e) = 0;
  if ((int)uVar5 == 0) {
    uVar4 = 0;
    lVar8 = 0x40;
    iVar18 = 0x40;
    uVar13 = 4;
    lVar14 = 0x40;
LAB_002d1eb0:
    uVar5 = (long)param_1 + uVar5 + 0x7a;
    uVar10 = uVar13 - 1;
    uVar11 = uVar5 + 0x10;
    uVar15 = (uint)uVar10 & 7;
    lVar9 = 1;
    *(undefined1 (*) [16])(uVar5 & 0xfffffff0) = (undefined1  [16])0x0;
    if (1 < uVar13) {
      uVar6 = uVar11;
      if ((uVar10 & 7) != 0) {
        if (uVar15 != 1) {
          if (uVar15 != 2) {
            if (uVar15 != 3) {
              if (uVar15 != 4) {
                if (uVar15 != 5) {
                  if (uVar15 != 6) {
                    lVar9 = 2;
                    uVar6 = uVar5 + 0x20;
                    *(undefined1 (*) [16])(uVar11 & 0xfffffff0) = (undefined1  [16])0x0;
                  }
                  lVar9 = lVar9 + 1;
                  uVar11 = uVar6 + 0x10;
                  *(undefined1 (*) [16])(uVar6 & 0xfffffff0) = (undefined1  [16])0x0;
                }
                lVar9 = lVar9 + 1;
                uVar6 = uVar11 + 0x10;
                *(undefined1 (*) [16])(uVar11 & 0xfffffff0) = (undefined1  [16])0x0;
              }
              lVar9 = lVar9 + 1;
              uVar11 = uVar6 + 0x10;
              *(undefined1 (*) [16])(uVar6 & 0xfffffff0) = (undefined1  [16])0x0;
            }
            lVar9 = lVar9 + 1;
            uVar6 = uVar11 + 0x10;
            *(undefined1 (*) [16])(uVar11 & 0xfffffff0) = (undefined1  [16])0x0;
          }
          lVar9 = lVar9 + 1;
          uVar11 = uVar6 + 0x10;
          *(undefined1 (*) [16])(uVar6 & 0xfffffff0) = (undefined1  [16])0x0;
        }
        uVar6 = uVar11 + 0x10;
        *(undefined1 (*) [16])(uVar11 & 0xfffffff0) = (undefined1  [16])0x0;
        if (uVar13 <= lVar9 + 1U) goto LAB_002d2004;
      }
      lVar9 = (((uVar10 & 0xffffffff) >> 3) - 1 & 0xffffffff) + 1;
      do {
        uVar17 = uVar6 + 0x10;
        uVar23 = uVar6 + 0x30;
        uVar10 = uVar6 + 0x20;
        uVar19 = uVar6 + 0x40;
        uVar5 = uVar6 + 0x50;
        uVar11 = uVar6 + 0x60;
        uVar13 = uVar6 + 0x70;
        *(undefined1 (*) [16])(uVar6 & 0xfffffff0) = (undefined1  [16])0x0;
        uVar6 = uVar6 + 0x80;
        *(undefined1 (*) [16])(uVar17 & 0xfffffff0) = (undefined1  [16])0x0;
        *(undefined1 (*) [16])(uVar10 & 0xfffffff0) = (undefined1  [16])0x0;
        *(undefined1 (*) [16])(uVar23 & 0xfffffff0) = (undefined1  [16])0x0;
        *(undefined1 (*) [16])(uVar19 & 0xfffffff0) = (undefined1  [16])0x0;
        *(undefined1 (*) [16])(uVar5 & 0xfffffff0) = (undefined1  [16])0x0;
        *(undefined1 (*) [16])(uVar11 & 0xfffffff0) = (undefined1  [16])0x0;
        *(undefined1 (*) [16])(uVar13 & 0xfffffff0) = (undefined1  [16])0x0;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
    }
LAB_002d2004:
    lVar8 = lVar8 - lVar14;
    uVar4 = uVar4 + lVar14;
    if (iVar18 == (int)lVar14) goto LAB_002d216c;
  }
  else {
    uVar13 = uVar5 - 1;
    *(undefined1 *)(((ulong)param_1 & 0xffffffff) + 0x7a) = 0;
    uVar15 = (uint)uVar13 & 7;
    uVar4 = 1;
    if (1 < uVar5) {
      if ((uVar13 & 7) != 0) {
        if (uVar15 != 1) {
          if (uVar15 != 2) {
            if (uVar15 != 3) {
              if (uVar15 != 4) {
                if (uVar15 != 5) {
                  if (uVar15 != 6) {
                    uVar4 = 2;
                    *(undefined1 *)(((long)param_1 + 1U & 0xffffffff) + 0x7a) = 0;
                  }
                  uVar11 = (long)param_1 + uVar4;
                  uVar4 = uVar4 + 1;
                  *(undefined1 *)((uVar11 & 0xffffffff) + 0x7a) = 0;
                }
                uVar11 = (long)param_1 + uVar4;
                uVar4 = uVar4 + 1;
                *(undefined1 *)((uVar11 & 0xffffffff) + 0x7a) = 0;
              }
              uVar11 = (long)param_1 + uVar4;
              uVar4 = uVar4 + 1;
              *(undefined1 *)((uVar11 & 0xffffffff) + 0x7a) = 0;
            }
            uVar11 = (long)param_1 + uVar4;
            uVar4 = uVar4 + 1;
            *(undefined1 *)((uVar11 & 0xffffffff) + 0x7a) = 0;
          }
          uVar11 = (long)param_1 + uVar4;
          uVar4 = uVar4 + 1;
          *(undefined1 *)((uVar11 & 0xffffffff) + 0x7a) = 0;
        }
        uVar11 = (long)param_1 + uVar4;
        uVar4 = uVar4 + 1;
        *(undefined1 *)((uVar11 & 0xffffffff) + 0x7a) = 0;
        if (uVar5 <= uVar4) goto LAB_002d1e8c;
      }
      lVar14 = (((uVar13 & 0xffffffff) >> 3) - 1 & 0xffffffff) + 1;
      do {
        lVar21 = uVar4 + 1;
        lVar22 = uVar4 + 3;
        lVar9 = uVar4 + 2;
        lVar12 = uVar4 + 4;
        lVar16 = uVar4 + 5;
        lVar20 = uVar4 + 6;
        lVar8 = uVar4 + 7;
        *(undefined1 *)(((long)param_1 + uVar4 & 0xffffffff) + 0x7a) = 0;
        uVar4 = uVar4 + 8;
        *(undefined1 *)(((long)param_1 + lVar21 & 0xffffffffU) + 0x7a) = 0;
        *(undefined1 *)(((long)param_1 + lVar9 & 0xffffffffU) + 0x7a) = 0;
        *(undefined1 *)(((long)param_1 + lVar22 & 0xffffffffU) + 0x7a) = 0;
        *(undefined1 *)(((long)param_1 + lVar12 & 0xffffffffU) + 0x7a) = 0;
        *(undefined1 *)(((long)param_1 + lVar16 & 0xffffffffU) + 0x7a) = 0;
        *(undefined1 *)(((long)param_1 + lVar20 & 0xffffffffU) + 0x7a) = 0;
        *(undefined1 *)(((long)param_1 + lVar8 & 0xffffffffU) + 0x7a) = 0;
        lVar14 = lVar14 + -1;
      } while (lVar14 != 0);
    }
LAB_002d1e8c:
    lVar8 = 0x40 - uVar4;
    if ((int)uVar5 == 0x40) goto LAB_002d216c;
    iVar18 = (int)(0x40 - uVar5);
    uVar13 = (0x40 - uVar5 & 0xffffffff) >> 4;
    lVar14 = uVar13 << 4;
    if ((int)lVar14 != 0) goto LAB_002d1eb0;
  }
  uVar13 = lVar8 - 1;
  uVar24 = (uint)uVar13;
  uVar15 = uVar24 & 7;
  uVar5 = (long)param_1 + uVar4 + 0x7b;
  *(undefined1 *)((long)param_1 + uVar4 + 0x7a & 0xffffffff) = 0;
  if (uVar24 != 0) {
    if ((uVar13 & 7) != 0) {
      if (uVar15 != 1) {
        if (uVar15 != 2) {
          if (uVar15 != 3) {
            if (uVar15 != 4) {
              if (uVar15 != 5) {
                if (uVar15 != 6) {
                  puVar1 = (undefined1 *)(uVar5 & 0xffffffff);
                  uVar24 = (int)lVar8 - 2;
                  uVar5 = (long)param_1 + uVar4 + 0x7c;
                  *puVar1 = 0;
                }
                puVar1 = (undefined1 *)(uVar5 & 0xffffffff);
                uVar24 = uVar24 - 1;
                uVar5 = uVar5 + 1;
                *puVar1 = 0;
              }
              puVar1 = (undefined1 *)(uVar5 & 0xffffffff);
              uVar24 = uVar24 - 1;
              uVar5 = uVar5 + 1;
              *puVar1 = 0;
            }
            puVar1 = (undefined1 *)(uVar5 & 0xffffffff);
            uVar24 = uVar24 - 1;
            uVar5 = uVar5 + 1;
            *puVar1 = 0;
          }
          puVar1 = (undefined1 *)(uVar5 & 0xffffffff);
          uVar24 = uVar24 - 1;
          uVar5 = uVar5 + 1;
          *puVar1 = 0;
        }
        puVar1 = (undefined1 *)(uVar5 & 0xffffffff);
        uVar24 = uVar24 - 1;
        uVar5 = uVar5 + 1;
        *puVar1 = 0;
      }
      puVar1 = (undefined1 *)(uVar5 & 0xffffffff);
      uVar5 = uVar5 + 1;
      *puVar1 = 0;
      if (uVar24 == 1) goto LAB_002d216c;
    }
    lVar14 = (((uVar13 & 0xffffffff) >> 3) - 1 & 0xffffffff) + 1;
    do {
      uVar6 = uVar5 + 1;
      uVar17 = uVar5 + 3;
      uVar13 = uVar5 + 2;
      uVar11 = uVar5 + 4;
      uVar19 = uVar5 + 5;
      uVar4 = uVar5 + 6;
      uVar10 = uVar5 + 7;
      *(undefined1 *)(uVar5 & 0xffffffff) = 0;
      uVar5 = uVar5 + 8;
      *(undefined1 *)(uVar6 & 0xffffffff) = 0;
      *(undefined1 *)(uVar13 & 0xffffffff) = 0;
      *(undefined1 *)(uVar17 & 0xffffffff) = 0;
      *(undefined1 *)(uVar11 & 0xffffffff) = 0;
      *(undefined1 *)(uVar19 & 0xffffffff) = 0;
      *(undefined1 *)(uVar4 & 0xffffffff) = 0;
      *(undefined1 *)(uVar10 & 0xffffffff) = 0;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
  }
LAB_002d216c:
  lVar14 = func_0x002cff08();
  *(int *)((ulong)*(uint *)(lVar14 + 0x18) + 8) = (int)param_1;
  return;
}



// ===== function 0x889398 =====

/* WARNING: Removing unreachable block (ram,0x00889560) */
/* WARNING: Removing unreachable block (ram,0x00889570) */
/* WARNING: Removing unreachable block (ram,0x008896fc) */

ulong FUN_00889398(ulong param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar7;
  ulong uVar5;
  ulong uVar6;
  char cVar8;
  ulong uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  
  iVar7 = FUN_002c2198(param_2 + 0x16a0);
  if (iVar7 == 0) {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    puVar12 = (undefined1 *)(param_1 + 4);
    *puVar12 = 0;
    uVar9 = (ulong)uRam0000000000e9a514 /* 'There are no Announcements' */;
    if ((((ulong)puVar12 & 0xffffffff) <= uVar9) &&
       (uVar9 < ((ulong)(puVar12 + *(uint *)(param_1 + 0x14)) & 0xffffffff))) {
      func_0x0074a020(param_1 & 0xffffffff,param_1 & 0xffffffff,uVar9 - (long)puVar12 & 0xffffffff,
                      0x1a);
      return param_1 & 0xffffffff;
    }
    cVar8 = func_0x00720a28(param_1 & 0xffffffff,0x1a,0);
    if (cVar8 != '\0') {
      puVar10 = puVar12;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        puVar10 = (undefined1 *)(ulong)*(uint *)(param_1 + 4);
      }
      puVar11 = (undefined1 *)(ulong)uRam0000000000e9a514 /* 'There are no Announcements' */;
      uVar1 = puVar11[1];
      uVar2 = puVar11[2];
      uVar3 = puVar11[3];
      *puVar10 = *puVar11;
      puVar10[1] = uVar1;
      puVar10[2] = uVar2;
      puVar10[3] = uVar3;
      uVar1 = puVar11[5];
      uVar2 = puVar11[6];
      uVar3 = puVar11[7];
      puVar10[4] = puVar11[4];
      puVar10[5] = uVar1;
      puVar10[6] = uVar2;
      puVar10[7] = uVar3;
      uVar1 = puVar11[9];
      uVar2 = puVar11[10];
      uVar3 = puVar11[0xb];
      puVar10[8] = puVar11[8];
      puVar10[9] = uVar1;
      puVar10[10] = uVar2;
      puVar10[0xb] = uVar3;
      uVar1 = puVar11[0xd];
      uVar2 = puVar11[0xe];
      uVar3 = puVar11[0xf];
      puVar10[0xc] = puVar11[0xc];
      puVar10[0xd] = uVar1;
      puVar10[0xe] = uVar2;
      puVar10[0xf] = uVar3;
      uVar1 = puVar11[0x11];
      uVar2 = puVar11[0x12];
      uVar3 = puVar11[0x13];
      puVar10[0x10] = puVar11[0x10];
      puVar10[0x11] = uVar1;
      puVar10[0x12] = uVar2;
      puVar10[0x13] = uVar3;
      uVar1 = puVar11[0x15];
      uVar2 = puVar11[0x16];
      uVar3 = puVar11[0x17];
      puVar10[0x14] = puVar11[0x14];
      puVar10[0x15] = uVar1;
      puVar10[0x16] = uVar2;
      puVar10[0x17] = uVar3;
      uVar1 = puVar11[0x18];
      puVar10[0x19] = puVar11[0x19];
      puVar10[0x18] = uVar1;
      if (0xf < *(uint *)(param_1 + 0x18)) {
        puVar12 = (undefined1 *)(ulong)*(uint *)(param_1 + 4);
      }
      *(undefined4 *)(param_1 + 0x14) = 0x1a;
      puVar12[0x1a] = 0;
      return param_1 & 0xffffffff;
    }
    goto LAB_00889514;
  }
  uVar5 = FUN_002c2198(param_2 + 0x16a0);
  uVar9 = uVar5 & 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  puVar12 = (undefined1 *)(param_1 + 4);
  *puVar12 = 0;
  uVar6 = func_0x0071b078(uVar9);
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    if ((((ulong)puVar12 & 0xffffffff) <= (uVar5 & 0xffffffff)) &&
       ((uVar5 & 0xffffffff) < ((ulong)(puVar12 + *(uint *)(param_1 + 0x14)) & 0xffffffff)))
    goto LAB_008894f0;
  }
  else if (((ulong)*(uint *)(param_1 + 4) <= (uVar5 & 0xffffffff)) &&
          ((uVar5 & 0xffffffff) < (ulong)(*(uint *)(param_1 + 4) + *(int *)(param_1 + 0x14)))) {
LAB_008894f0:
    if (0xf < *(uint *)(param_1 + 0x18)) {
      puVar12 = (undefined1 *)(ulong)*(uint *)(param_1 + 4);
    }
    func_0x0074a020(param_1 & 0xffffffff,param_1 & 0xffffffff,uVar5 - (long)puVar12 & 0xffffffff,
                    uVar6 & 0xffffffff);
    goto LAB_00889514;
  }
  uVar5 = uVar6 & 0xffffffff;
  cVar8 = func_0x00720a28(param_1 & 0xffffffff,uVar5,0);
  if (cVar8 != '\0') {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      func_0x0071b098((ulong)puVar12 & 0xffffffff,uVar9,uVar5);
      uVar4 = *(uint *)(param_1 + 0x18);
    }
    else {
      func_0x0071b098(*(undefined4 *)(param_1 + 4),uVar9,uVar5);
      uVar4 = *(uint *)(param_1 + 0x18);
    }
    if (uVar4 < 0x10) {
      *(int *)(param_1 + 0x14) = (int)uVar6;
      *(undefined1 *)((ulong)(puVar12 + uVar6) & 0xffffffff) = 0;
    }
    else {
      *(int *)(param_1 + 0x14) = (int)uVar6;
      *(undefined1 *)(*(uint *)(param_1 + 4) + uVar6 & 0xffffffff) = 0;
    }
    return param_1 & 0xffffffff;
  }
LAB_00889514:
  return param_1 & 0xffffffff;
}



// ===== function 0x88a2c0 =====

/* WARNING: Removing unreachable block (ram,0x0088a304) */
/* WARNING: Removing unreachable block (ram,0x0088a314) */
/* WARNING: Removing unreachable block (ram,0x0088a32c) */

ulong FUN_0088a2c0(ulong param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  char cVar5;
  undefined1 *puVar6;
  ulong uVar7;
  undefined1 *puVar8;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  puVar6 = (undefined1 *)(param_1 + 4);
  *puVar6 = 0;
  uVar7 = (ulong)uRam0000000000e9a51c /* 'Announcement Not Available' */;
  if ((uVar7 < ((ulong)puVar6 & 0xffffffff)) ||
     (((ulong)(puVar6 + *(uint *)(param_1 + 0x14)) & 0xffffffff) <= uVar7)) {
    cVar5 = func_0x00720a28(param_1 & 0xffffffff,0x1a,0);
    if (cVar5 != '\0') {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        puVar8 = (undefined1 *)(ulong)uRam0000000000e9a51c /* 'Announcement Not Available' */;
        uVar1 = puVar8[1];
        uVar2 = puVar8[2];
        uVar3 = puVar8[3];
        *puVar6 = *puVar8;
        *(undefined1 *)(param_1 + 5) = uVar1;
        *(undefined1 *)(param_1 + 6) = uVar2;
        *(undefined1 *)(param_1 + 7) = uVar3;
        uVar1 = puVar8[5];
        uVar2 = puVar8[6];
        uVar3 = puVar8[7];
        *(undefined1 *)(param_1 + 8) = puVar8[4];
        *(undefined1 *)(param_1 + 9) = uVar1;
        *(undefined1 *)(param_1 + 10) = uVar2;
        *(undefined1 *)(param_1 + 0xb) = uVar3;
        uVar1 = puVar8[8];
        uVar2 = puVar8[10];
        uVar3 = puVar8[0xb];
        *(undefined1 *)(param_1 + 0xd) = puVar8[9];
        *(undefined1 *)(param_1 + 0xf) = uVar3;
        *(undefined1 *)(param_1 + 0xc) = uVar1;
        *(undefined1 *)(param_1 + 0xe) = uVar2;
        uVar1 = puVar8[0xd];
        uVar2 = puVar8[0xe];
        uVar3 = puVar8[0xf];
        *(undefined1 *)(param_1 + 0x10) = puVar8[0xc];
        *(undefined1 *)(param_1 + 0x11) = uVar1;
        *(undefined1 *)(param_1 + 0x12) = uVar2;
        *(undefined1 *)(param_1 + 0x13) = uVar3;
        uVar1 = puVar8[0x11];
        uVar2 = puVar8[0x12];
        uVar3 = puVar8[0x13];
        *(undefined1 *)(param_1 + 0x14) = puVar8[0x10];
        *(undefined1 *)(param_1 + 0x15) = uVar1;
        *(undefined1 *)(param_1 + 0x16) = uVar2;
        *(undefined1 *)(param_1 + 0x17) = uVar3;
        uVar1 = puVar8[0x15];
        uVar2 = puVar8[0x16];
        uVar3 = puVar8[0x17];
        *(undefined1 *)(param_1 + 0x18) = puVar8[0x14];
        *(undefined1 *)(param_1 + 0x19) = uVar1;
        *(undefined1 *)(param_1 + 0x1a) = uVar2;
        *(undefined1 *)(param_1 + 0x1b) = uVar3;
        uVar1 = puVar8[0x18];
        *(undefined1 *)(param_1 + 0x1d) = puVar8[0x19];
        *(undefined1 *)(param_1 + 0x1c) = uVar1;
        uVar4 = *(uint *)(param_1 + 0x18);
      }
      else {
        puVar8 = (undefined1 *)(ulong)uRam0000000000e9a51c /* 'Announcement Not Available' */;
        puVar6 = (undefined1 *)(ulong)*(uint *)(param_1 + 4);
        uVar1 = puVar8[1];
        uVar2 = puVar8[2];
        uVar3 = puVar8[3];
        *puVar6 = *puVar8;
        puVar6[1] = uVar1;
        puVar6[2] = uVar2;
        puVar6[3] = uVar3;
        uVar1 = puVar8[5];
        uVar2 = puVar8[6];
        uVar3 = puVar8[7];
        puVar6[4] = puVar8[4];
        puVar6[7] = uVar3;
        puVar6[5] = uVar1;
        puVar6[6] = uVar2;
        uVar1 = puVar8[9];
        uVar2 = puVar8[10];
        uVar3 = puVar8[0xb];
        puVar6[8] = puVar8[8];
        puVar6[9] = uVar1;
        puVar6[10] = uVar2;
        puVar6[0xb] = uVar3;
        uVar1 = puVar8[0xd];
        uVar2 = puVar8[0xe];
        uVar3 = puVar8[0xf];
        puVar6[0xc] = puVar8[0xc];
        puVar6[0xd] = uVar1;
        puVar6[0xe] = uVar2;
        puVar6[0xf] = uVar3;
        uVar1 = puVar8[0x12];
        uVar2 = puVar8[0x11];
        uVar3 = puVar8[0x13];
        puVar6[0x10] = puVar8[0x10];
        puVar6[0x11] = uVar2;
        puVar6[0x12] = uVar1;
        puVar6[0x13] = uVar3;
        uVar1 = puVar8[0x15];
        uVar2 = puVar8[0x16];
        uVar3 = puVar8[0x17];
        puVar6[0x14] = puVar8[0x14];
        puVar6[0x15] = uVar1;
        puVar6[0x16] = uVar2;
        puVar6[0x17] = uVar3;
        uVar1 = puVar8[0x18];
        puVar6[0x19] = puVar8[0x19];
        puVar6[0x18] = uVar1;
        uVar4 = *(uint *)(param_1 + 0x18);
      }
      if (uVar4 < 0x10) {
        *(undefined4 *)(param_1 + 0x14) = 0x1a;
        *(undefined1 *)(param_1 + 0x1e) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0x14) = 0x1a;
        *(undefined1 *)((ulong)*(uint *)(param_1 + 4) + 0x1a) = 0;
      }
      return param_1 & 0xffffffff;
    }
  }
  else {
    func_0x0074a020(param_1 & 0xffffffff,param_1 & 0xffffffff,uVar7 - (long)puVar6 & 0xffffffff,0x1a
                   );
  }
  return param_1 & 0xffffffff;
}



// ===== function 0x2b6f80 =====

long FUN_002b6f80(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  
  uVar3 = (ulong)*(uint *)(param_1 + 0x38);
  uVar2 = *(uint *)(param_1 + 4);
  if (param_2 < *(int *)(((ulong)uVar2 +
                          (-(long)(int)(uVar2 ^ 0x80000000) - 0x80000000U &
                          -(ulong)(0xffffffff80000000 < (ulong)(long)(int)(uVar2 ^ 0x80000000))) &
                         0xfffffff) * 0x10 + uVar3 & 0xffffffff)) {
    uVar2 = *(uint *)(param_1 + 0x18);
LAB_002b6fe4:
    return (long)(int)uVar2;
  }
  if ((int)uVar2 < 2) goto LAB_002b6fe4;
  if (param_2 < *(int *)((ulong)*(uint *)(param_1 + 0x38) + 0x20)) {
    uVar2 = 1;
    goto LAB_002b6fe4;
  }
  uVar4 = 2;
  uVar1 = uVar2 - 2 & 7;
  if (uVar1 != 0) {
    uVar4 = 3;
    iVar5 = 3;
    if ((int)uVar2 < 3) goto LAB_002b6fe4;
    if (param_2 < *(int *)(uVar3 + 0x30 & 0xffffffff)) goto LAB_002b71fc;
    if (uVar1 != 1) {
      if (uVar1 != 2) {
        if (uVar1 != 3) {
          if (uVar1 != 4) {
            if (uVar1 != 5) {
              if (uVar1 != 6) {
                uVar4 = 4;
                iVar5 = 4;
                if (param_2 < *(int *)(uVar3 + 0x40 & 0xffffffff)) goto LAB_002b71fc;
              }
              uVar4 = uVar4 + 1;
              iVar5 = (int)uVar4;
              if (param_2 < *(int *)(uVar4 * 0x10 + uVar3 & 0xffffffff)) goto LAB_002b71fc;
            }
            uVar4 = uVar4 + 1;
            iVar5 = (int)uVar4;
            if (param_2 < *(int *)(uVar4 * 0x10 + uVar3 & 0xffffffff)) goto LAB_002b71fc;
          }
          uVar4 = uVar4 + 1;
          iVar5 = (int)uVar4;
          if (param_2 < *(int *)(uVar4 * 0x10 + uVar3 & 0xffffffff)) goto LAB_002b71fc;
        }
        uVar4 = uVar4 + 1;
        iVar5 = (int)uVar4;
        if (param_2 < *(int *)(uVar4 * 0x10 + uVar3 & 0xffffffff)) goto LAB_002b71fc;
      }
      uVar4 = uVar4 + 1;
      iVar5 = (int)uVar4;
      if (param_2 < *(int *)(uVar4 * 0x10 + uVar3 & 0xffffffff)) goto LAB_002b71fc;
    }
  }
  do {
    iVar5 = (int)(uVar4 + 1);
    if ((int)uVar2 < iVar5) goto LAB_002b6fe4;
    if (param_2 < *(int *)((uVar4 + 1 & 0xfffffff) * 0x10 + uVar3 & 0xffffffff)) break;
    iVar5 = (int)(uVar4 + 2);
    if (param_2 < *(int *)((uVar4 + 2 & 0xfffffff) * 0x10 + uVar3 & 0xffffffff)) break;
    iVar5 = (int)(uVar4 + 3);
    if (param_2 < *(int *)((uVar4 + 3 & 0xfffffff) * 0x10 + uVar3 & 0xffffffff)) break;
    iVar5 = (int)(uVar4 + 4);
    if (param_2 < *(int *)((uVar4 + 4 & 0xfffffff) * 0x10 + uVar3 & 0xffffffff)) break;
    iVar5 = (int)(uVar4 + 5);
    if (param_2 < *(int *)((uVar4 + 5 & 0xfffffff) * 0x10 + uVar3 & 0xffffffff)) break;
    iVar5 = (int)(uVar4 + 6);
    if (param_2 < *(int *)((uVar4 + 6 & 0xfffffff) * 0x10 + uVar3 & 0xffffffff)) break;
    iVar5 = (int)(uVar4 + 7);
    if (param_2 < *(int *)((uVar4 + 7 & 0xfffffff) * 0x10 + uVar3 & 0xffffffff)) break;
    uVar4 = uVar4 + 8;
    iVar5 = (int)uVar4;
  } while (*(int *)((uVar4 & 0xfffffff) * 0x10 + uVar3 & 0xffffffff) <= param_2);
LAB_002b71fc:
  return (long)(iVar5 + -1);
}



// ===== function 0x2b6e98 =====

int FUN_002b6e98(long param_1,uint param_2)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  
  lVar4 = (ulong)*(uint *)(param_1 + 4) - 1;
  uVar1 = (ulong)(int)((uint)lVar4 ^ 0x80000000);
  uVar3 = (ulong)(int)(((param_2 ^ 0x80000000) + 0x7fffffff &
                       ~-(uint)((param_2 ^ 0x80000000) < 0x80000001)) + 1 ^ 0x80000000);
  lVar4 = lVar4 + (uVar3 - uVar1 & -(ulong)(uVar3 < uVar1));
  iVar6 = (int)lVar4;
  iVar5 = 0;
  if ((((10 < iVar6) && (iVar5 = 3, 0x14 < iVar6)) && (iVar5 = 6, 0x1e < iVar6)) &&
     (iVar5 = 9, 0x28 < iVar6)) {
    iVar5 = 0xc;
  }
  iVar2 = iVar5 + 1;
  uVar1 = (long)(iVar6 / 10 + (iVar6 >> 0x1f)) - (long)(iVar6 >> 0x1f);
  lVar4 = lVar4 - ((uVar1 & 0x7fffffff) * 2 + (uVar1 & 0x1fffffff) * 8);
  if ((2 < (lVar4 - 1U & 0xffffffff)) && (iVar2 = iVar5 + 3, (lVar4 - 4U & 0xffffffff) < 4)) {
    iVar2 = iVar5 + 2;
  }
  return iVar2;
}



// ===== function 0x2b94c0 =====

void FUN_002b94c0(long param_1)

{
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return;
}



// ===== function 0x77778 =====

void FUN_00077778(ulong param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar6;
  long lVar4;
  undefined4 uVar7;
  char cVar8;
  uint *puVar5;
  undefined1 uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  char *pcVar13;
  ulong uVar14;
  undefined1 auStack_130 [8];
  undefined1 auStack_128 [4];
  uint uStack_124;
  uint uStack_120;
  undefined4 uStack_11c;
  undefined1 auStack_118 [4];
  uint uStack_114;
  uint uStack_110;
  undefined4 uStack_10c;
  undefined1 auStack_108 [4];
  uint uStack_104;
  uint uStack_100;
  undefined1 auStack_f8 [4];
  uint uStack_f4;
  undefined4 uStack_e4;
  uint uStack_e0;
  undefined1 auStack_dc [4];
  undefined4 uStack_d8;
  uint uStack_c4;
  undefined1 auStack_c0 [4];
  uint auStack_bc [4];
  undefined4 uStack_ac;
  uint uStack_a8;
  undefined1 auStack_a4 [4];
  uint uStack_a0;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined1 auStack_88 [4];
  uint uStack_84;
  undefined4 uStack_74;
  uint uStack_70;
  undefined1 auStack_6c [4];
  uint uStack_68;
  undefined4 uStack_58;
  uint uStack_54;
  
  iVar6 = func_0x0040a290();
  if ((iVar6 == 8) || (iVar6 == 6)) {
    lVar4 = (long)iVar6;
  }
  else {
    lVar4 = 2;
  }
  uVar14 = param_1 & 0xffffffff;
  func_0x0071b858(lVar4);
  func_0x00038018(auStack_c0,uVar14);
  if (uStack_a8 < 0x10) {
    func_0x0071b868((ulong)auStack_bc & 0xffffffff);
    if (uStack_a8 < 0x10) goto LAB_00077808;
LAB_00077b58:
    func_0x0071b0c8(auStack_bc[0]);
    auStack_bc[0] = auStack_bc[0] & 0xffffff;
    uStack_a8 = 0xf;
    uStack_ac = 0;
    if (*(int *)((ulong)*(uint *)((ulong)uRam0000000000e903c0 + 0x90) + 0x20) == 0x240) {
LAB_00078468:
      uStack_a8 = 0xf;
      uStack_ac = 0;
      func_0x0071b898(1);
    }
    func_0x0071b878((long)*(int *)((ulong)uRam0000000000e8f9f0 + 0xc));
    func_0x00407ca0((ulong)auStack_130 & 0xffffffff);
    func_0x00406bb8(param_1 + 0x130 & 0xffffffff,(ulong)auStack_130 & 0xffffffff);
    func_0x00406bb8(param_1 + 0x138 & 0xffffffff,uRam0000000000e92758);
    *(undefined1 *)(param_1 + 0x14c) = 0;
  }
  else {
    func_0x0071b868(auStack_bc[0]);
    if (0xf < uStack_a8) goto LAB_00077b58;
LAB_00077808:
    uStack_ac = 0;
    uStack_a8 = 0xf;
    auStack_bc[0] = auStack_bc[0] & 0xffffff;
    if (*(int *)((ulong)*(uint *)((ulong)uRam0000000000e903c0 + 0x90) + 0x20) == 0x240)
    goto LAB_00078468;
    func_0x0071b878((long)*(int *)((ulong)uRam0000000000e8f9f0 + 0xc));
    func_0x00407ca0((ulong)auStack_130 & 0xffffffff);
    func_0x00406bb8(param_1 + 0x130 & 0xffffffff,(ulong)auStack_130 & 0xffffffff);
    func_0x00406bb8(param_1 + 0x138 & 0xffffffff,uRam0000000000e92758);
    *(undefined1 *)(param_1 + 0x14c) = 0;
  }
  uVar7 = func_0x0071b0b8(1);
  func_0x0071b888(uVar7);
  uVar1 = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(uVar14 + 0xdc44) = uVar7;
  func_0x001bee38(uVar7,param_1 + 0xdabc & 0xffffffff,uVar1,*(undefined4 *)(uVar14 + 0xdacc));
  func_0x0015ade0();
  func_0x001485b8();
  uVar10 = (ulong)auStack_dc & 0xffffffff;
  func_0x0074a310(uVar10,uRam0000000000e9275c /* 'data/ai/VehiclesAndCharacters.XML' */);
  cVar8 = func_0x001e5218(*(undefined4 *)(param_1 + 0x150));
  if (cVar8 != '\0') {
    func_0x0074a498(uVar10,uRam0000000000e92760 /* 'data/ai/DemoVehiclesAndCharacters.XML' */);
  }
  func_0x002302b8(uVar10);
  uStack_11c = 0;
  uStack_124 = 0;
  uStack_120 = 0;
  cVar8 = func_0x001e5218(*(undefined4 *)(param_1 + 0x150));
  if (cVar8 == '\0') {
    func_0x0024ebb0((ulong)auStack_118 & 0xffffffff,uRam0000000000e90334,uRam0000000000e92774 /* 'data/events/tickets/' */,
                    uRam0000000000e92778 /* '*.ticket' */);
    func_0x007653a0(auStack_128,(ulong)auStack_118 & 0xffffffff);
    uVar10 = (ulong)uStack_114;
    if (uStack_114 == 0) {
LAB_00078454:
      uStack_10c = 0;
      uStack_114 = 0;
      uStack_110 = 0;
      goto LAB_00077d10;
    }
    if (uStack_114 == uStack_110) {
      func_0x0071b0c8(uStack_110);
      goto LAB_00078454;
    }
    uVar12 = uVar10 + 0x1c;
    func_0x00749fa0(uStack_114);
    uVar2 = (int)(((uStack_110 - uVar10) - 0x1c & 0xffffffff) >> 2) * 7 & 7;
    if (uStack_110 != (uint)uVar12) {
      if (uVar2 != 0) {
        if (uVar2 != 1) {
          if (uVar2 != 2) {
            if (uVar2 != 3) {
              if (uVar2 != 4) {
                if (uVar2 != 5) {
                  if (uVar2 != 6) {
                    uVar11 = uVar12 & 0xffffffff;
                    uVar12 = uVar10 + 0x38;
                    func_0x00749fa0(uVar11);
                  }
                  uVar10 = uVar12 & 0xffffffff;
                  uVar12 = uVar12 + 0x1c;
                  func_0x00749fa0(uVar10);
                }
                uVar10 = uVar12 & 0xffffffff;
                uVar12 = uVar12 + 0x1c;
                func_0x00749fa0(uVar10);
              }
              uVar10 = uVar12 & 0xffffffff;
              uVar12 = uVar12 + 0x1c;
              func_0x00749fa0(uVar10);
            }
            uVar10 = uVar12 & 0xffffffff;
            uVar12 = uVar12 + 0x1c;
            func_0x00749fa0(uVar10);
          }
          uVar10 = uVar12 & 0xffffffff;
          uVar12 = uVar12 + 0x1c;
          func_0x00749fa0(uVar10);
        }
        uVar10 = uVar12 & 0xffffffff;
        uVar12 = uVar12 + 0x1c;
        func_0x00749fa0(uVar10);
        if (uStack_110 == (uint)uVar12) goto LAB_00077b04;
      }
      do {
        uVar11 = uVar12 + 0xc4;
        func_0x00749fa0(uVar12 & 0xffffffff);
        func_0x00749fa0(uVar12 + 0x1c & 0xffffffff);
        func_0x00749fa0(uVar12 + 0x38 & 0xffffffff);
        func_0x00749fa0(uVar12 + 0x54 & 0xffffffff);
        func_0x00749fa0(uVar12 + 0x70 & 0xffffffff);
        func_0x00749fa0(uVar12 + 0x8c & 0xffffffff);
        uVar10 = uVar12 + 0xa8;
        uVar12 = uVar12 + 0xe0;
        func_0x00749fa0(uVar10 & 0xffffffff);
        func_0x00749fa0(uVar11 & 0xffffffff);
      } while (uStack_110 != (uint)uVar12);
    }
LAB_00077b04:
    func_0x0071b0c8(uStack_114);
    puVar5 = (uint *)(ulong)*(uint *)(param_1 + 0x38);
    uStack_10c = 0;
    uStack_114 = 0;
    uStack_110 = 0;
    uVar2 = *(uint *)((ulong)*puVar5 + 0x1c);
  }
  else {
    func_0x0074a310((ulong)auStack_a4 & 0xffffffff,uRam0000000000e92764 /* 'GamersdayDemo1.ticket' */);
    func_0x00768028(auStack_128,(ulong)auStack_a4 & 0xffffffff);
    if (0xf < uStack_8c) {
      func_0x0071b0c8(uStack_a0);
    }
    uStack_a0 = uStack_a0 & 0xffffff;
    uStack_8c = 0xf;
    uStack_90 = 0;
    func_0x0074a310((ulong)auStack_88 & 0xffffffff,uRam0000000000e92768 /* 'gamersdaydemo1b.ticket' */);
    func_0x00768028(auStack_128,(ulong)auStack_88 & 0xffffffff);
    if (0xf < uStack_70) {
      func_0x0071b0c8(uStack_84);
    }
    uStack_70 = 0xf;
    uStack_84 = uStack_84 & 0xffffff;
    uStack_74 = 0;
    func_0x0074a310((ulong)auStack_6c & 0xffffffff,uRam0000000000e9276c /* 'gamersdaydemo1c.ticket' */);
    func_0x00768028(auStack_128,(ulong)auStack_6c & 0xffffffff);
    if (0xf < uStack_54) {
      func_0x0071b0c8(uStack_68);
    }
    uStack_54 = 0xf;
    uStack_68 = uStack_68 & 0xffffff;
    uStack_58 = 0;
    func_0x0074a310((ulong)auStack_f8 & 0xffffffff,uRam0000000000e92770 /* 'GamersdayDemo2.ticket' */);
    func_0x00768028(auStack_128,(ulong)auStack_f8 & 0xffffffff);
    if (0xf < uStack_e0) {
      func_0x0071b0c8(uStack_f4);
    }
    uStack_f4 = uStack_f4 & 0xffffff;
    uStack_e0 = 0xf;
    uStack_e4 = 0;
LAB_00077d10:
    puVar5 = (uint *)(ulong)*(uint *)(param_1 + 0x38);
    uVar2 = *(uint *)((ulong)*puVar5 + 0x1c);
  }
  cVar8 = (*(code *)(ulong)*(uint *)(ulong)uVar2)(puVar5);
  if (cVar8 == '\0') {
    uVar9 = func_0x001e5218(*(undefined4 *)(param_1 + 0x150));
    uVar1 = uRam0000000000e90334;
    func_0x00252f30(uRam0000000000e90334,uRam0000000000e92774 /* 'data/events/tickets/' */,auStack_128,uVar9);
    cVar8 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(param_1 +
                                                                                       0x38) + 0x1c)
            )((uint *)(ulong)*(uint *)(param_1 + 0x38));
    if (cVar8 != '\0') goto LAB_00077d4c;
    func_0x001312b0();
    cVar8 = func_0x001e5218(*(undefined4 *)(param_1 + 0x150));
    uVar7 = uRam0000000000e9277c /* 'data/trophiesandrewards/' */;
    if (cVar8 == '\0') {
      func_0x0025a128(uRam0000000000e9277c /* 'data/trophiesandrewards/' */,uRam0000000000e92780 /* '*.trophy' */);
      func_0x0024a540(uVar7,uRam0000000000e92784 /* '*.reward' */);
      func_0x0024aad8(auStack_108,*(undefined4 *)(uVar14 + 0xdad0),*(undefined4 *)(uVar14 + 0xdb00))
      ;
      uVar10 = (ulong)uStack_104;
      if (uStack_104 != 0) {
        if (uStack_100 != uStack_104) {
          uVar11 = uVar10 + 0xa8;
          uVar12 = (((uStack_100 - uVar10) - 0xa8 & 0xffffffff) >> 3) * 5;
          uVar2 = (uint)uVar12 & 7;
          func_0x0074c840(uStack_104);
          if (uStack_100 != (uint)uVar11) {
            if ((uVar12 & 7) != 0) {
              if (uVar2 != 1) {
                if (uVar2 != 2) {
                  if (uVar2 != 3) {
                    if (uVar2 != 4) {
                      if (uVar2 != 5) {
                        if (uVar2 != 6) {
                          uVar12 = uVar11 & 0xffffffff;
                          uVar11 = uVar10 + 0x150;
                          func_0x0074c840(uVar12);
                        }
                        uVar10 = uVar11 & 0xffffffff;
                        uVar11 = uVar11 + 0xa8;
                        func_0x0074c840(uVar10);
                      }
                      uVar10 = uVar11 & 0xffffffff;
                      uVar11 = uVar11 + 0xa8;
                      func_0x0074c840(uVar10);
                    }
                    uVar10 = uVar11 & 0xffffffff;
                    uVar11 = uVar11 + 0xa8;
                    func_0x0074c840(uVar10);
                  }
                  uVar10 = uVar11 & 0xffffffff;
                  uVar11 = uVar11 + 0xa8;
                  func_0x0074c840(uVar10);
                }
                uVar10 = uVar11 & 0xffffffff;
                uVar11 = uVar11 + 0xa8;
                func_0x0074c840(uVar10);
              }
              uVar10 = uVar11 & 0xffffffff;
              uVar11 = uVar11 + 0xa8;
              func_0x0074c840(uVar10);
              if (uStack_100 == (uint)uVar11) goto LAB_00078170;
            }
            do {
              func_0x0074c840(uVar11 & 0xffffffff);
              func_0x0074c840(uVar11 + 0xa8 & 0xffffffff);
              func_0x0074c840(uVar11 + 0x150 & 0xffffffff);
              func_0x0074c840(uVar11 + 0x1f8 & 0xffffffff);
              func_0x0074c840(uVar11 + 0x2a0 & 0xffffffff);
              func_0x0074c840(uVar11 + 0x348 & 0xffffffff);
              func_0x0074c840(uVar11 + 0x3f0 & 0xffffffff);
              uVar10 = uVar11 + 0x498;
              uVar11 = uVar11 + 0x540;
              func_0x0074c840(uVar10 & 0xffffffff);
            } while (uStack_100 != (uint)uVar11);
          }
        }
LAB_00078170:
        func_0x0071b0c8(uStack_104);
      }
    }
    uVar10 = param_1 + 0xdcdc & 0xffffffff;
    func_0x0024ffb0(uVar1,1,uVar10,0,*(undefined4 *)(uVar14 + 0xdad0));
    func_0x00253d90(uVar1,1,uVar10,0,*(undefined4 *)(uVar14 + 0xdad0));
    func_0x002536f0(uVar1);
    (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(uVar14 + 0xbf40) +
                                              0x164))((uint *)(ulong)*(uint *)(uVar14 + 0xbf40));
    uVar1 = uRam0000000000e90374;
    pcVar13 = (char *)(ulong)uRam0000000000e90370;
    if (*pcVar13 == '\0') {
      FUN_002b94c0(uRam0000000000e90374);
      uVar7 = uRam0000000000e90378;
      *pcVar13 = '\x01';
      func_0x0071b348(uVar7);
    }
    func_0x002b9508(uVar1,uRam0000000000e92788 /* 'data/onlinerankings/' */,uRam0000000000e9278c /* 'rankings.xml' */);
    func_0x0076a410(uVar10);
    func_0x001f1a20();
    uVar7 = uRam0000000000e92794 /* 'data/ai/defaultPS3.brain' */;
    uVar1 = uRam0000000000e92790;
    *(undefined1 *)(param_1 + 0x24) = 1;
    func_0x000a13e8(uVar1,uVar7);
    func_0x000769a0(uVar14);
    uVar2 = uStack_120;
    uVar14 = (ulong)uStack_124;
    if (uStack_124 == 0) goto LAB_00077ed8;
    uVar10 = (ulong)uStack_120;
    if (uStack_124 != uStack_120) {
      uVar12 = uVar14 + 0x1c;
      func_0x00749fa0(uStack_124);
      uVar3 = (int)(((uVar10 - uVar14) - 0x1c & 0xffffffff) >> 2) * 7 & 7;
      if (uVar2 != (uint)uVar12) {
        if (uVar3 != 0) {
          if (uVar3 != 1) {
            if (uVar3 != 2) {
              if (uVar3 != 3) {
                if (uVar3 != 4) {
                  if (uVar3 != 5) {
                    if (uVar3 != 6) {
                      uVar10 = uVar12 & 0xffffffff;
                      uVar12 = uVar14 + 0x38;
                      func_0x00749fa0(uVar10);
                    }
                    uVar14 = uVar12 & 0xffffffff;
                    uVar12 = uVar12 + 0x1c;
                    func_0x00749fa0(uVar14);
                  }
                  uVar14 = uVar12 & 0xffffffff;
                  uVar12 = uVar12 + 0x1c;
                  func_0x00749fa0(uVar14);
                }
                uVar14 = uVar12 & 0xffffffff;
                uVar12 = uVar12 + 0x1c;
                func_0x00749fa0(uVar14);
              }
              uVar14 = uVar12 & 0xffffffff;
              uVar12 = uVar12 + 0x1c;
              func_0x00749fa0(uVar14);
            }
            uVar14 = uVar12 & 0xffffffff;
            uVar12 = uVar12 + 0x1c;
            func_0x00749fa0(uVar14);
          }
          uVar14 = uVar12 & 0xffffffff;
          uVar12 = uVar12 + 0x1c;
          func_0x00749fa0(uVar14);
          if (uVar2 == (uint)uVar12) goto LAB_000783f4;
        }
        do {
          func_0x00749fa0(uVar12 & 0xffffffff);
          func_0x00749fa0(uVar12 + 0x1c & 0xffffffff);
          func_0x00749fa0(uVar12 + 0x38 & 0xffffffff);
          func_0x00749fa0(uVar12 + 0x54 & 0xffffffff);
          uVar10 = uVar12 + 0xc4;
          func_0x00749fa0(uVar12 + 0x70 & 0xffffffff);
          func_0x00749fa0(uVar12 + 0x8c & 0xffffffff);
          uVar14 = uVar12 + 0xa8;
          uVar12 = uVar12 + 0xe0;
          func_0x00749fa0(uVar14 & 0xffffffff);
          func_0x00749fa0(uVar10 & 0xffffffff);
        } while (uVar2 != (uint)uVar12);
      }
LAB_000783f4:
      uVar14 = (ulong)uStack_124;
    }
  }
  else {
LAB_00077d4c:
    uVar2 = uStack_120;
    uVar14 = (ulong)uStack_124;
    if (uStack_124 == 0) goto LAB_00077ed8;
    uVar10 = (ulong)uStack_120;
    if (uStack_124 != uStack_120) {
      uVar12 = uVar14 + 0x1c;
      func_0x00749fa0(uStack_124);
      uVar3 = (int)(((uVar10 - uVar14) - 0x1c & 0xffffffff) >> 2) * 7 & 7;
      if (uVar2 != (uint)uVar12) {
        if (uVar3 != 0) {
          if (uVar3 != 1) {
            if (uVar3 != 2) {
              if (uVar3 != 3) {
                if (uVar3 != 4) {
                  if (uVar3 != 5) {
                    if (uVar3 != 6) {
                      uVar10 = uVar12 & 0xffffffff;
                      uVar12 = uVar14 + 0x38;
                      func_0x00749fa0(uVar10);
                    }
                    uVar14 = uVar12 & 0xffffffff;
                    uVar12 = uVar12 + 0x1c;
                    func_0x00749fa0(uVar14);
                  }
                  uVar14 = uVar12 & 0xffffffff;
                  uVar12 = uVar12 + 0x1c;
                  func_0x00749fa0(uVar14);
                }
                uVar14 = uVar12 & 0xffffffff;
                uVar12 = uVar12 + 0x1c;
                func_0x00749fa0(uVar14);
              }
              uVar14 = uVar12 & 0xffffffff;
              uVar12 = uVar12 + 0x1c;
              func_0x00749fa0(uVar14);
            }
            uVar14 = uVar12 & 0xffffffff;
            uVar12 = uVar12 + 0x1c;
            func_0x00749fa0(uVar14);
          }
          uVar14 = uVar12 & 0xffffffff;
          uVar12 = uVar12 + 0x1c;
          func_0x00749fa0(uVar14);
          if (uVar2 == (uint)uVar12) goto LAB_00077ecc;
        }
        do {
          func_0x00749fa0(uVar12 & 0xffffffff);
          func_0x00749fa0(uVar12 + 0x1c & 0xffffffff);
          func_0x00749fa0(uVar12 + 0x38 & 0xffffffff);
          func_0x00749fa0(uVar12 + 0x54 & 0xffffffff);
          func_0x00749fa0(uVar12 + 0x70 & 0xffffffff);
          func_0x00749fa0(uVar12 + 0x8c & 0xffffffff);
          func_0x00749fa0(uVar12 + 0xa8 & 0xffffffff);
          uVar14 = uVar12 + 0xc4;
          uVar12 = uVar12 + 0xe0;
          func_0x00749fa0(uVar14 & 0xffffffff);
        } while (uVar2 != (uint)uVar12);
      }
LAB_00077ecc:
      func_0x0071b0c8(uStack_124);
      goto LAB_00077ed8;
    }
  }
  func_0x0071b0c8(uVar14);
LAB_00077ed8:
  uStack_11c = 0;
  uStack_124 = 0;
  uStack_120 = 0;
  if (0xf < uStack_c4) {
    func_0x0071b0c8(uStack_d8);
  }
  return;
}



