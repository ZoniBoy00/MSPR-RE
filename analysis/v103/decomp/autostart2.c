// ===== function 0x109f48 =====

void FUN_00109f48(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  char cVar7;
  int iVar6;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined1 auStack_60 [40];
  
  uVar10 = (ulong)auStack_60 & 0xffffffff;
  func_0x0074a758(uVar10,param_2 & 0xffffffff);
  cVar7 = func_0x00109cc8(param_1 + 0x98U & 0xffffffff,uVar10);
  func_0x00749fa0(uVar10);
  if (cVar7 == '\0') {
    return;
  }
  *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + -1;
  uVar1 = *(uint *)(param_1 + 0x90);
  uVar2 = *(uint *)(param_2 + 0x14);
  uVar10 = (ulong)uVar2;
  if (uVar1 < 0x10) {
    uVar3 = *(uint *)(param_1 + 0x8c);
    uVar8 = param_1 + 0x7c;
  }
  else {
    uVar8 = (ulong)*(uint *)(param_1 + 0x7c);
    uVar3 = *(uint *)(param_1 + 0x8c);
  }
  uVar4 = (ulong)uVar3;
  if (uVar2 != 0) {
    if (*(uint *)(param_2 + 0x18) < 0x10) {
      param_2 = param_2 + 4;
    }
    else {
      param_2 = (ulong)*(uint *)(param_2 + 4);
    }
    uVar9 = uVar10;
    if (uVar4 < uVar10) {
      uVar9 = uVar4;
    }
    iVar6 = func_0x0071b318(param_2 & 0xffffffff,uVar8 & 0xffffffff,uVar9);
    if (iVar6 != 0) {
      return;
    }
  }
  if (uVar10 < uVar4) {
    return;
  }
  if (uVar2 != uVar3) {
    return;
  }
  if (uVar1 < 0x10) {
    lVar5 = uVar4 + param_1 + 0x7c;
    if ((int)lVar5 != 0) {
      uVar10 = lVar5 - (param_1 + 0x7c);
      goto joined_r0x0010a15c;
    }
  }
  else {
    lVar5 = uVar4 + *(uint *)(param_1 + 0x7c);
    if ((int)lVar5 != 0) {
      uVar10 = lVar5 - (ulong)*(uint *)(param_1 + 0x7c);
      goto joined_r0x0010a15c;
    }
  }
  uVar10 = 0;
joined_r0x0010a15c:
  if (uVar4 < (uVar10 & 0xffffffff)) {
    uVar10 = uVar4;
  }
  if ((int)uVar10 != 0) {
    if (*(uint *)(param_1 + 0x90) < 0x10) {
      uVar8 = param_1 + 0x7c;
    }
    else {
      uVar8 = (ulong)*(uint *)(param_1 + 0x7c);
    }
    func_0x0071b088(uVar8 & 0xffffffff,uVar8 + uVar10 & 0xffffffff,uVar4 - uVar10 & 0xffffffff);
    lVar5 = *(uint *)(param_1 + 0x8c) - uVar10;
    if (*(uint *)(param_1 + 0x90) < 0x10) {
      uVar10 = param_1 + 0x7c;
    }
    else {
      uVar10 = (ulong)*(uint *)(param_1 + 0x7c);
    }
    *(int *)(param_1 + 0x8c) = (int)lVar5;
    *(undefined1 *)(uVar10 + lVar5 & 0xffffffff) = 0;
  }
  return;
}



// ===== function 0x10c300 =====

void FUN_0010c300(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  undefined1 *puVar7;
  uint *puVar8;
  undefined4 *puVar9;
  int iVar10;
  char cVar12;
  undefined4 uVar11;
  undefined1 *puVar13;
  undefined1 *puVar14;
  ulong uVar15;
  undefined1 auStack_90 [4];
  uint auStack_8c [2];
  undefined1 auStack_82 [6];
  uint uStack_7c;
  uint uStack_78;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  
  *param_1 = uRam0000000000e94bc8;
  func_0x00720ef0((ulong)(param_1 + 1) & 0xffffffff,0,0);
  func_0x00720ef0((ulong)(param_1 + 8) & 0xffffffff,0,0);
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  func_0x00720ef0((ulong)(param_1 + 0x17) & 0xffffffff,0,0);
  func_0x00720ef0((ulong)(param_1 + 0x1e) & 0xffffffff,0,0);
  puVar9 = (undefined4 *)func_0x0071b0b8(0x48);
  iVar10 = (int)puVar9;
  if (iVar10 == 0) {
    if ((int)(puVar9 + 1) != 0) {
      puVar9[1] = 0;
    }
LAB_0010c700:
    if ((int)(puVar9 + 2) != 0) {
      puVar9[2] = 0;
    }
LAB_0010c710:
    *(undefined1 *)(puVar9 + 0x11) = 1;
    param_1[0x27] = iVar10;
    *(undefined1 *)((long)puVar9 + 0x45) = 1;
    uVar4 = param_1[0x27];
  }
  else {
    *puVar9 = 0;
    if ((int)(puVar9 + 1) == 0) goto LAB_0010c700;
    puVar9[1] = 0;
    if ((int)(puVar9 + 2) == 0) goto LAB_0010c710;
    puVar9[2] = 0;
    *(undefined1 *)(puVar9 + 0x11) = 1;
    param_1[0x27] = iVar10;
    *(undefined1 *)((long)puVar9 + 0x45) = 1;
    uVar4 = param_1[0x27];
  }
  *(uint *)((ulong)uVar4 + 4) = uVar4;
  param_1[0x28] = 0;
  *(undefined4 *)(ulong)(uint)param_1[0x27] = param_1[0x27];
  *(undefined4 *)((ulong)(uint)param_1[0x27] + 8) = param_1[0x27];
  func_0x00720ef0(auStack_90,0,0);
  uStack_68 = 0;
  puVar8 = auStack_8c;
  uStack_70 = 0;
  uStack_6c = 0;
  if (0xf < uStack_78) {
    puVar8 = (uint *)(ulong)auStack_8c[0];
  }
  uVar15 = (ulong)uRam0000000000e94c00 /* 'NoSuchPage' */;
  if (uVar15 < ((ulong)puVar8 & 0xffffffff)) {
LAB_0010c4ac:
    cVar12 = func_0x00720a28(auStack_90,10,0);
    if (cVar12 != '\0') {
      puVar8 = auStack_8c;
      if (0xf < uStack_78) {
        puVar8 = (uint *)(ulong)auStack_8c[0];
      }
      puVar14 = (undefined1 *)(ulong)uRam0000000000e94c00 /* 'NoSuchPage' */;
      puVar7 = (undefined1 *)((ulong)puVar8 & 0xffffffff);
      puVar13 = auStack_82;
      uVar1 = puVar14[1];
      uVar2 = puVar14[2];
      uVar3 = puVar14[3];
      *puVar7 = *puVar14;
      puVar7[1] = uVar1;
      puVar7[2] = uVar2;
      puVar7[3] = uVar3;
      uVar1 = puVar14[5];
      uVar2 = puVar14[6];
      uVar3 = puVar14[7];
      puVar7[4] = puVar14[4];
      puVar7[5] = uVar1;
      puVar7[6] = uVar2;
      puVar7[7] = uVar3;
      uVar1 = puVar14[8];
      puVar7[9] = puVar14[9];
      puVar7[8] = uVar1;
      if (0xf < uStack_78) {
        puVar13 = (undefined1 *)((ulong)auStack_8c[0] + 10);
      }
      uStack_7c = 10;
      *(undefined1 *)((ulong)puVar13 & 0xffffffff) = 0;
    }
    iVar10 = param_1[0x10];
    if (iVar10 != 0) goto LAB_0010c4d8;
LAB_0010c644:
    iVar5 = param_1[0x11];
  }
  else {
    puVar8 = auStack_8c;
    if (0xf < uStack_78) {
      puVar8 = (uint *)(ulong)auStack_8c[0];
    }
    if (((long)puVar8 + (ulong)uStack_7c & 0xffffffff) <= uVar15) goto LAB_0010c4ac;
    puVar8 = auStack_8c;
    if (0xf < uStack_78) {
      puVar8 = (uint *)(ulong)auStack_8c[0];
    }
    uVar6 = (ulong)auStack_90 & 0xffffffff;
    func_0x0074a020(uVar6,uVar6,uVar15 - (long)puVar8 & 0xffffffff,10);
    iVar10 = param_1[0x10];
    if (iVar10 == 0) goto LAB_0010c644;
LAB_0010c4d8:
    iVar5 = param_1[0x11];
    if ((uint)((iVar5 - iVar10 >> 2) * -0x45d1745d) <
        (uint)((param_1[0x12] - iVar10 >> 2) * -0x45d1745d)) {
      if (iVar5 != 0) {
        func_0x007a2010(iVar5,auStack_90);
      }
      param_1[0x11] = iVar5 + 0x2c;
      goto LAB_0010c534;
    }
  }
  func_0x007a3720((ulong)(param_1 + 0xf) & 0xffffffff,iVar5,1,auStack_90);
LAB_0010c534:
  param_1[0x29] = 0;
  param_1[0x13] = 0;
  param_1[0x2a] = 0;
  *(undefined1 *)(param_1 + 0x25) = 0;
  func_0x0071b038((ulong)(param_1 + 0x2b) & 0xffffffff,0,0x44);
  uVar11 = func_0x0071b0b8(0x18);
  func_0x002c18d0(uVar11,1,0,0);
  param_1[0x15] = uVar11;
  func_0x0079fbf0(auStack_90);
  return;
}



// ===== function 0x10cef8 =====

char FUN_0010cef8(uint *param_1,int param_2,uint param_3)

{
  ulong uVar1;
  ulong uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  ulong uVar7;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  ulong uVar8;
  char cVar13;
  int iVar12;
  uint *puVar14;
  ulong uVar15;
  ulong uVar16;
  undefined1 auStack_120 [28];
  undefined1 auStack_104 [4];
  uint auStack_100 [4];
  uint uStack_f0;
  uint uStack_ec;
  undefined1 auStack_e8 [4];
  uint auStack_e4 [5];
  uint uStack_d0;
  undefined1 auStack_cc [4];
  uint auStack_c8 [4];
  uint uStack_b8;
  uint uStack_b4;
  undefined1 auStack_b0 [28];
  undefined1 auStack_94 [4];
  uint auStack_90 [4];
  uint uStack_80;
  uint uStack_7c;
  
  func_0x0074a310(auStack_cc,uRam0000000000e94c2c /* '-autotest' */);
  iVar12 = 0;
  uVar10 = param_3;
  if (param_2 < 1) {
    iVar12 = 0;
LAB_0010d03c:
    if (param_2 != iVar12) {
      if (iVar12 + 2 < param_2) {
        uVar8 = (ulong)auStack_e8 & 0xffffffff;
        func_0x0074a310(uVar8,*(undefined4 *)(ulong)((iVar12 + 1) * 4 + param_3));
        func_0x0074a498((ulong)(param_1 + 8) & 0xffffffff,
                        *(undefined4 *)(ulong)((iVar12 + 2) * 4 + param_3));
        uVar2 = (ulong)param_1 & 0xffffffff;
        uVar10 = func_0x0071b7b8(*(undefined4 *)(ulong)((iVar12 + 3) * 4 + param_3),0,10);
        param_1[0x29] = uVar10;
        uVar11 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_1 + 0xc))(uVar2);
        uVar15 = (ulong)auStack_104 & 0xffffffff;
        func_0x0074a310(uVar15,uVar11);
        func_0x0079fc58(uVar15,uVar8,0,0xffffffff);
        uVar10 = uRam0000000000e94c34 /* '.xml' */;
        uVar8 = (ulong)uStack_f0;
        if ((uStack_f0 != 0) && (3 < uStack_f0)) {
          puVar6 = auStack_100;
          if (0xf < uStack_ec) {
            puVar6 = (uint *)(ulong)auStack_100[0];
          }
          uVar8 = uVar8 - 3;
          while (uVar15 = func_0x00bdf5c0((ulong)puVar6 & 0xffffffff,0x2e,uVar8 & 0xffffffff),
                (int)uVar15 != 0) {
            iVar12 = func_0x0071b318(uVar15 & 0xffffffff,uVar10,4);
            if (iVar12 == 0) {
              puVar6 = auStack_100;
              if (0xf < uStack_ec) {
                puVar6 = (uint *)(ulong)auStack_100[0];
              }
              uVar8 = (ulong)uStack_f0;
              if ((uVar15 - (long)puVar6 & 0xffffffff) < uVar8) goto LAB_0010d1a8;
              goto LAB_0010d134;
            }
            uVar8 = (long)puVar6 + (uVar8 - uVar15) + -1;
            puVar6 = (uint *)(uVar15 + 1);
          }
          uVar8 = (ulong)uStack_f0;
        }
LAB_0010d134:
        uVar15 = (ulong)uVar10;
        puVar6 = auStack_100;
        if (0xf < uStack_ec) {
          puVar6 = (uint *)(ulong)auStack_100[0];
        }
        if (uVar15 < ((ulong)puVar6 & 0xffffffff)) {
LAB_0010d35c:
          if ((~uVar8 & 0xffffffff) < 5) {
            func_0x0071b0d8(auStack_104);
            uVar8 = (ulong)uStack_f0;
          }
          uVar15 = uVar8 + 4;
          if ((int)uVar8 == -5) {
            func_0x0071b0d8(auStack_104);
          }
          uVar8 = (ulong)uStack_ec;
          uVar10 = (uint)uVar15;
          if (uVar8 < (uVar15 & 0xffffffff)) {
            uVar7 = uVar15 | 0xf;
            uVar16 = uVar15;
            if ((((int)uVar7 != -1) &&
                (uVar1 = (ulong)(uStack_ec >> 1), uVar16 = uVar7,
                (uVar15 & 0xffffffff | 0xf) / 3 < uVar1)) && (uVar8 <= (-uVar1 - 2 & 0xffffffff))) {
              uVar16 = uVar8 + uVar1;
            }
            puVar6 = (uint *)func_0x0071b0b8(uVar16 + 1 & 0xffffffff);
            if (uStack_f0 != 0) {
              puVar14 = auStack_100;
              if (0xf < uStack_ec) {
                puVar14 = (uint *)(ulong)auStack_100[0];
              }
              func_0x0071b098((ulong)puVar6 & 0xffffffff,(ulong)puVar14 & 0xffffffff,uStack_f0);
            }
            func_0x00720ef0(auStack_104,1,0);
            auStack_100[0] = (uint)puVar6;
            uStack_ec = (uint)uVar16;
            puVar14 = auStack_100;
            if (0xf < (uVar16 & 0xffffffff)) {
              puVar14 = puVar6;
            }
            *(undefined1 *)((long)puVar14 + (ulong)uStack_f0 & 0xffffffff) = 0;
            if (uVar10 != 0) {
              uVar8 = uVar16 & 0xffffffff;
              goto LAB_0010d47c;
            }
          }
          else if (uVar10 == 0) {
            puVar6 = auStack_100;
            if (0xf < uVar8) {
              puVar6 = (uint *)(ulong)auStack_100[0];
            }
            uStack_f0 = 0;
            *(undefined1 *)((ulong)puVar6 & 0xffffffff) = 0;
          }
          else {
LAB_0010d47c:
            puVar6 = auStack_100;
            if (0xf < uVar8) {
              puVar6 = (uint *)(ulong)auStack_100[0];
            }
            puVar3 = (undefined1 *)((long)puVar6 + (ulong)uStack_f0 & 0xffffffff);
            puVar6 = auStack_100;
            puVar3[3] = 0x6c;
            *puVar3 = 0x2e;
            puVar3[1] = 0x78;
            puVar3[2] = 0x6d;
            if (0xf < uStack_ec) {
              puVar6 = (uint *)(ulong)auStack_100[0];
            }
            *(undefined1 *)((long)puVar6 + uVar15 & 0xffffffff) = 0;
            uStack_f0 = uVar10;
          }
        }
        else {
          puVar6 = auStack_100;
          if (0xf < uStack_ec) {
            puVar6 = (uint *)(ulong)auStack_100[0];
          }
          if (((long)puVar6 + uVar8 & 0xffffffff) <= uVar15) goto LAB_0010d35c;
          puVar6 = auStack_100;
          if (0xf < uStack_ec) {
            puVar6 = (uint *)(ulong)auStack_100[0];
          }
          uVar15 = uVar15 - (long)puVar6;
          if (uVar8 < (uVar15 & 0xffffffff)) {
            func_0x0071b0a8(auStack_104);
            uVar8 = (ulong)uStack_f0;
          }
          uVar16 = uVar8 - uVar15;
          if (3 < (uVar16 & 0xffffffff)) {
            uVar16 = 4;
          }
          if ((~uVar8 & 0xffffffff) <= (uVar16 & 0xffffffff)) {
            func_0x0071b0d8(auStack_104);
          }
          if ((int)uVar16 != 0) {
            uVar8 = uVar16 + uStack_f0;
            cVar13 = func_0x00720a28(auStack_104,uVar8 & 0xffffffff,0);
            if (cVar13 != '\0') {
              if (uStack_ec < 0x10) {
                puVar6 = auStack_100;
                uVar7 = (ulong)uStack_f0 + (long)puVar6;
              }
              else {
                puVar6 = (uint *)(ulong)auStack_100[0];
                uVar7 = (long)puVar6 + (ulong)uStack_f0;
              }
              func_0x0071b098(uVar7 & 0xffffffff,(long)puVar6 + uVar15 & 0xffffffff,
                              uVar16 & 0xffffffff);
              puVar6 = auStack_100;
              if (0xf < uStack_ec) {
                puVar6 = (uint *)(ulong)auStack_100[0];
              }
              *(undefined1 *)((long)puVar6 + uVar8 & 0xffffffff) = 0;
              uStack_f0 = (uint)uVar8;
            }
          }
        }
LAB_0010d1a8:
        puVar6 = auStack_100;
        uVar10 = *(uint *)((ulong)*param_1 + 0x10);
        if (0xf < uStack_ec) {
          puVar6 = (uint *)(ulong)auStack_100[0];
        }
        uVar8 = (ulong)auStack_b0 & 0xffffffff;
        func_0x0074a758(uVar8,(ulong)(param_1 + 1) & 0xffffffff);
        cVar13 = (*(code *)(ulong)*(uint *)(ulong)uVar10)(uVar2,(ulong)puVar6 & 0xffffffff,uVar8);
        func_0x00749fa0(uVar8);
        if (cVar13 == '\0') {
          puVar6 = auStack_100;
          if (0xf < uStack_ec) {
            puVar6 = (uint *)(ulong)auStack_100[0];
          }
          func_0x00108640(uRam0000000000e94c38 /* "Failed to read AutoTest file '%s'" */,(ulong)puVar6 & 0xffffffff);
          cVar13 = '\0';
        }
        else {
          uVar8 = (ulong)auStack_120 & 0xffffffff;
          func_0x0074a758(uVar8,(ulong)(param_1 + 1) & 0xffffffff);
          cVar13 = func_0x0010c880(uVar2,uVar8);
          func_0x00749fa0(uVar8);
          if (cVar13 != '\0') {
            (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_1 + 8))(uVar2);
            (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_1 + 0x1c))(uVar2);
            puVar6 = auStack_e4;
            if (0xf < uStack_d0) {
              puVar6 = (uint *)(ulong)auStack_e4[0];
            }
            if (param_1[0xe] < 0x10) {
              puVar14 = param_1 + 9;
            }
            else {
              puVar14 = (uint *)(ulong)param_1[9];
            }
            func_0x00108760(uRam0000000000e94c3c /* 'AutoTest has been configured to execute %s:%s with a minimum of %d players' */,(ulong)puVar6 & 0xffffffff,
                            (ulong)puVar14 & 0xffffffff,(long)(int)param_1[0x29]);
          }
        }
        func_0x00749fa0(auStack_104);
        func_0x00749fa0(auStack_e8);
        goto LAB_0010d28c;
      }
      func_0x00108640(uRam0000000000e94c30 /* 'Insufficient command line arguments. Usage: -autotest [Config file name] [id string] [mini' */);
    }
  }
  else {
    do {
      func_0x0074a310((ulong)auStack_94 & 0xffffffff,*(undefined4 *)(ulong)uVar10);
      uVar5 = uStack_80;
      uVar4 = uStack_b8;
      if (uStack_b4 < 0x10) {
        puVar6 = auStack_c8;
        if (uStack_80 != 0) goto LAB_0010cf90;
LAB_0010d020:
        if ((uVar4 <= uVar5) && (uVar5 == uVar4)) {
LAB_0010d030:
          func_0x00749fa0(auStack_94);
          goto LAB_0010d03c;
        }
      }
      else {
        puVar6 = (uint *)(ulong)auStack_c8[0];
        if (uStack_80 == 0) goto LAB_0010d020;
LAB_0010cf90:
        puVar14 = auStack_90;
        if (0xf < uStack_7c) {
          puVar14 = (uint *)(ulong)auStack_90[0];
        }
        if (uStack_b8 < uStack_80) {
          iVar9 = func_0x0071b318((ulong)puVar14 & 0xffffffff,(ulong)puVar6 & 0xffffffff,uStack_b8);
          if (iVar9 != 0) goto LAB_0010cfc8;
          goto LAB_0010d020;
        }
        iVar9 = func_0x0071b318((ulong)puVar14 & 0xffffffff,(ulong)puVar6 & 0xffffffff,uStack_80);
        if (iVar9 == 0) goto LAB_0010d020;
LAB_0010cfc8:
        if (iVar9 == 0) goto LAB_0010d030;
      }
      iVar12 = iVar12 + 1;
      uVar10 = uVar10 + 4;
      func_0x00749fa0((ulong)auStack_94 & 0xffffffff);
    } while (param_2 != iVar12);
  }
  cVar13 = '\0';
LAB_0010d28c:
  func_0x00749fa0(auStack_cc);
  return cVar13;
}



