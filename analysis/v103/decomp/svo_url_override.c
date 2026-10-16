// ===== function 0x1a2b20 =====

void FUN_001a2b20(undefined1 *param_1)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  ulong uVar8;
  undefined1 auStack_2d0 [28];
  undefined1 auStack_2b4 [28];
  undefined1 auStack_298 [28];
  undefined1 auStack_27c [28];
  undefined1 auStack_260 [28];
  undefined1 auStack_244 [28];
  undefined1 auStack_228 [28];
  undefined1 auStack_20c [28];
  undefined1 auStack_1f0 [28];
  undefined1 auStack_1d4 [28];
  undefined1 auStack_1b8 [28];
  undefined1 auStack_19c [28];
  undefined1 auStack_180 [28];
  undefined1 auStack_164 [28];
  undefined1 auStack_148 [28];
  undefined1 auStack_12c [28];
  undefined1 auStack_110 [28];
  undefined1 auStack_f4 [28];
  undefined1 auStack_d8 [28];
  undefined1 auStack_bc [28];
  undefined1 auStack_a0 [28];
  undefined1 auStack_84 [44];
  
  uVar6 = func_0x0071c738();
  uVar5 = uRam0000000000e96fc0 /* 'DebugOptions' */;
  uVar8 = (ulong)auStack_84 & 0xffffffff;
  uVar1 = (ulong)auStack_1d4 & 0xffffffff;
  func_0x0074a310(uVar8,uRam0000000000e96fc0 /* 'DebugOptions' */);
  func_0x0074a310(uVar1,uRam0000000000e96fc4 /* 'enableResourceMemoryTracking' */);
  func_0x007d1770(uVar6,uVar8,uVar1,(ulong)param_1 & 0xffffffff);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar6 = func_0x0071c738();
  uVar8 = (ulong)auStack_1f0 & 0xffffffff;
  uVar1 = (ulong)auStack_20c & 0xffffffff;
  func_0x0074a310(uVar8,uVar5);
  func_0x0074a310(uVar1,uRam0000000000e96fc8 /* 'showMemStats' */);
  func_0x007d1770(uVar6,uVar8,uVar1,(ulong)(param_1 + 1) & 0xffffffff);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar6 = func_0x0071c738();
  uVar8 = (ulong)auStack_228 & 0xffffffff;
  uVar1 = (ulong)auStack_244 & 0xffffffff;
  func_0x0074a310(uVar8,uVar5);
  func_0x0074a310(uVar1,uRam0000000000e96fcc /* 'enableRemoteConsole' */);
  func_0x007d1770(uVar6,uVar8,uVar1,(ulong)(param_1 + 5) & 0xffffffff);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar6 = func_0x0071c738();
  uVar8 = (ulong)auStack_260 & 0xffffffff;
  uVar1 = (ulong)auStack_27c & 0xffffffff;
  func_0x0074a310(uVar8,uVar5);
  func_0x0074a310(uVar1,uRam0000000000e96fd0 /* 'showFrameTimeInfo' */);
  func_0x007d1770(uVar6,uVar8,uVar1,(ulong)(param_1 + 2) & 0xffffffff);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar6 = func_0x0071c738();
  uVar8 = (ulong)auStack_298 & 0xffffffff;
  uVar1 = (ulong)auStack_2b4 & 0xffffffff;
  func_0x0074a310(uVar8,uVar5);
  func_0x0074a310(uVar1,uRam0000000000e96fd4 /* 'infiniteVetos' */);
  func_0x007d1770(uVar6,uVar8,uVar1,(ulong)(param_1 + 3) & 0xffffffff);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar6 = func_0x0071c738();
  uVar8 = (ulong)auStack_1b8 & 0xffffffff;
  uVar1 = (ulong)auStack_19c & 0xffffffff;
  func_0x0074a310(uVar8,uVar5);
  func_0x0074a310(uVar1,uRam0000000000e96fd8 /* 'quickOnlineRace' */);
  func_0x007d1770(uVar6,uVar8,uVar1,(ulong)(param_1 + 4) & 0xffffffff);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar6 = func_0x0071c738();
  uVar8 = (ulong)auStack_a0 & 0xffffffff;
  uVar1 = (ulong)auStack_bc & 0xffffffff;
  func_0x0074a310(uVar8,uVar5);
  func_0x0074a310(uVar1,uRam0000000000e96fdc /* 'useSVO' */);
  func_0x007d1770(uVar6,uVar8,uVar1,(ulong)(param_1 + 6) & 0xffffffff);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar6 = func_0x0071c738();
  uVar8 = (ulong)auStack_d8 & 0xffffffff;
  uVar1 = (ulong)auStack_f4 & 0xffffffff;
  func_0x0074a310(uVar8,uVar5);
  func_0x0074a310(uVar1,uRam0000000000e96fe0 /* 'svoDebug' */);
  func_0x007d1770(uVar6,uVar8,uVar1,(ulong)(param_1 + 7) & 0xffffffff);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar6 = func_0x0071c738();
  uVar8 = (ulong)auStack_110 & 0xffffffff;
  uVar1 = (ulong)auStack_12c & 0xffffffff;
  func_0x0074a310(uVar8,uVar5);
  func_0x0074a310(uVar1,uRam0000000000e96fe4 /* 'svoSSL' */);
  func_0x007d1770(uVar6,uVar8,uVar1,(ulong)(param_1 + 8) & 0xffffffff);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar6 = func_0x0071c738();
  uVar8 = (ulong)auStack_148 & 0xffffffff;
  uVar1 = (ulong)auStack_164 & 0xffffffff;
  func_0x0074a310(uVar8,uVar5);
  func_0x0074a310(uVar1,uRam0000000000e96fe8 /* 'mediusUniverse' */);
  uVar3 = (ulong)(param_1 + 0xc) & 0xffffffff;
  func_0x007d1c90(uVar6,uVar8,uVar1,uVar3);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar6 = func_0x0071c738();
  uVar8 = (ulong)auStack_180 & 0xffffffff;
  uVar1 = (ulong)auStack_2d0 & 0xffffffff;
  func_0x0074a310(uVar8,uVar5);
  func_0x0074a310(uVar1,uRam0000000000e96fec /* 'svoUrl' */);
  uVar4 = (ulong)(param_1 + 0x28) & 0xffffffff;
  func_0x007d1c90(uVar6,uVar8,uVar1,uVar4);
  func_0x00749fa0(uVar1);
  func_0x00749fa0(uVar8);
  uVar2 = *(uint *)(param_1 + 0x24);
  puVar7 = param_1 + 0x10;
  param_1[8] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (0xf < uVar2) {
    puVar7 = (undefined1 *)(ulong)*(uint *)(param_1 + 0x10);
  }
  uVar8 = (ulong)uRam0000000000e96fbc;
  if (((ulong)puVar7 & 0xffffffff) <= uVar8) {
    if (uVar2 < 0x10) {
      puVar7 = param_1 + 0x10;
    }
    else {
      puVar7 = (undefined1 *)(ulong)*(uint *)(param_1 + 0x10);
    }
    if (uVar8 < ((ulong)(puVar7 + *(uint *)(param_1 + 0x20)) & 0xffffffff)) {
      puVar7 = param_1 + 0x10;
      if (0xf < uVar2) {
        puVar7 = (undefined1 *)(ulong)*(uint *)(param_1 + 0x10);
      }
      func_0x0074a020(uVar3,uVar3,uVar8 - (long)puVar7 & 0xffffffff,0);
      uVar2 = *(uint *)(param_1 + 0x40);
      goto joined_r0x001a3150;
    }
  }
  puVar7 = param_1 + 0x10;
  if (0xf < uVar2) {
    puVar7 = (undefined1 *)(ulong)*(uint *)(param_1 + 0x10);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *puVar7 = 0;
  uVar2 = *(uint *)(param_1 + 0x40);
joined_r0x001a3150:
  if (uVar2 < 0x10) {
    uVar1 = (ulong)(param_1 + 0x2c) & 0xffffffff;
  }
  else {
    uVar1 = (ulong)*(uint *)(param_1 + 0x2c);
  }
  if (uVar1 <= uVar8) {
    if (uVar2 < 0x10) {
      puVar7 = param_1 + 0x2c;
    }
    else {
      puVar7 = (undefined1 *)(ulong)*(uint *)(param_1 + 0x2c);
    }
    if (uVar8 < ((ulong)(puVar7 + *(uint *)(param_1 + 0x3c)) & 0xffffffff)) {
      puVar7 = param_1 + 0x2c;
      if (0xf < uVar2) {
        puVar7 = (undefined1 *)(ulong)*(uint *)(param_1 + 0x2c);
      }
      func_0x0074a020(uVar4,uVar4,uVar8 - (long)puVar7 & 0xffffffff,0);
      return;
    }
  }
  puVar7 = param_1 + 0x2c;
  if (0xf < uVar2) {
    puVar7 = (undefined1 *)(ulong)*(uint *)(param_1 + 0x2c);
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *puVar7 = 0;
  return;
}



// ===== function 0x27bd88 =====

void FUN_0027bd88(undefined4 *param_1,long param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = uRam0000000000e99840;
  uVar4 = uRam0000000000e9983c;
  *(undefined1 *)((long)param_1 + 5) = 0;
  *param_1 = uVar4;
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = uVar2;
  func_0x0071b048((long)param_1 + 6U & 0xffffffff,param_2 + 0x24U & 0xffffffff);
  func_0x0071b048((long)param_1 + 0x86U & 0xffffffff,param_2 + 0xa4U & 0xffffffff);
  param_1[0x42] = *(undefined4 *)(param_2 + 0x124);
  iVar3 = func_0x002c1ed8();
  if (iVar3 == 0) {
    uVar1 = param_2 + 0x3bcU & 0xffffffff;
    func_0x0027c1b8(uRam0000000000e99848 /* 'Using SVO URL from universe %s' */,uVar1);
    func_0x0071b2c8((ulong)(param_1 + 0x43) & 0xffffffff,0x80,uVar1);
  }
  else {
    uVar4 = func_0x002c1ed8();
    func_0x0027c1b8(uRam0000000000e99844 /* 'Setting override SVO URL %s' */,uVar4);
    uVar4 = func_0x002c1ed8();
    func_0x0071b2c8((ulong)(param_1 + 0x43) & 0xffffffff,0x80,uVar4);
  }
  func_0x0071b038((ulong)(param_1 + 99) & 0xffffffff,0,0x100);
  func_0x0071b2c8((ulong)(param_1 + 99) & 0xffffffff,0x100,param_2 + 700U & 0xffffffff);
  return;
}



// ===== function 0x1a5668 =====

/* WARNING: Type propagation algorithm not settling */

void FUN_001a5668(undefined1 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar7;
  ulong uVar4;
  ulong uVar5;
  char cVar8;
  undefined4 *puVar6;
  undefined4 uVar9;
  uint uVar10;
  ulong uVar11;
  char *pcVar12;
  ulong uVar13;
  undefined4 uStack_150;
  uint uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  uint uStack_140;
  undefined1 auStack_13c [4];
  uint uStack_138;
  undefined4 uStack_128;
  uint uStack_124;
  undefined1 auStack_120 [4];
  uint uStack_11c;
  undefined4 uStack_10c;
  uint uStack_108;
  undefined1 auStack_104 [4];
  undefined4 uStack_100;
  uint uStack_ec;
  undefined1 auStack_e8 [4];
  uint uStack_e4;
  undefined4 uStack_d4;
  uint uStack_d0;
  undefined1 auStack_cc [4];
  uint uStack_c8;
  undefined4 uStack_b8;
  uint uStack_b4;
  undefined1 auStack_b0 [4];
  uint uStack_ac;
  undefined4 uStack_9c;
  uint uStack_98;
  
  uVar7 = func_0x0071c738();
  uVar9 = uRam0000000000e97088 /* 'BuildOptions' */;
  func_0x0074a310((ulong)auStack_e8 & 0xffffffff,uRam0000000000e97088 /* 'BuildOptions' */);
  func_0x0074a310((ulong)auStack_cc & 0xffffffff,uRam0000000000e9708c /* 'productionVersion' */);
  func_0x007d1770(uVar7,(ulong)auStack_e8 & 0xffffffff,(ulong)auStack_cc & 0xffffffff,
                  (ulong)param_1 & 0xffffffff);
  if (uStack_b4 < 0x10) {
    uStack_b8 = 0;
    uStack_b4 = 0xf;
    uStack_c8 = uStack_c8 & 0xffffff;
    if (0xf < uStack_d0) {
LAB_001a5900:
      uStack_b4 = 0xf;
      uStack_b8 = 0;
      func_0x0071b0c8(uStack_e4);
      goto LAB_001a590c;
    }
    uStack_d0 = 0xf;
    uStack_d4 = 0;
    uStack_e4 = uStack_e4 & 0xffffff;
    uVar7 = func_0x0071c738();
    func_0x0074a310((ulong)auStack_b0 & 0xffffffff,uVar9);
    func_0x0074a310((ulong)auStack_13c & 0xffffffff,uRam0000000000e97090 /* 'showVersion' */);
    func_0x007d1770(uVar7,(ulong)auStack_b0 & 0xffffffff,(ulong)auStack_13c & 0xffffffff,
                    (ulong)(param_1 + 1) & 0xffffffff);
    if (0xf < uStack_124) goto LAB_001a5b50;
    uStack_124 = 0xf;
    uStack_128 = 0;
    uStack_138 = uStack_138 & 0xffffff;
    if (0xf < uStack_98) goto LAB_001a5b40;
    uStack_98 = 0xf;
    uStack_9c = 0;
    uStack_ac = uStack_ac & 0xffffff;
    uVar4 = func_0x0071c738();
    uVar13 = (ulong)auStack_104 & 0xffffffff;
    uVar11 = (ulong)auStack_120 & 0xffffffff;
    func_0x0074a310(uVar13,uVar9);
    func_0x0074a310(uVar11,uRam0000000000e97094 /* 'build' */);
    uVar10 = uRam0000000000e96d9c;
    uVar9 = uRam0000000000e96d78;
    pcVar12 = (char *)(ulong)uRam0000000000e96d98;
    if (*pcVar12 == '\0') goto LAB_001a5b08;
    uStack_140 = uRam0000000000e96d9c;
    uStack_144 = uRam0000000000e97098;
    uStack_148 = uRam0000000000e9709c;
    uVar5 = func_0x0071c748(uVar4 & 0xffffffff,uVar13);
    if ((int)uVar5 != 0) {
      cVar8 = func_0x0071c758(uVar5 & 0xffffffff,uVar11);
      goto joined_r0x001a5a64;
    }
  }
  else {
    func_0x0071b0c8(uStack_c8);
    uStack_c8 = uStack_c8 & 0xffffff;
    uStack_b4 = 0xf;
    uStack_b8 = 0;
    if (0xf < uStack_d0) goto LAB_001a5900;
LAB_001a590c:
    uStack_e4 = uStack_e4 & 0xffffff;
    uStack_d0 = 0xf;
    uStack_d4 = 0;
    uVar7 = func_0x0071c738();
    func_0x0074a310((ulong)auStack_b0 & 0xffffffff,uVar9);
    func_0x0074a310((ulong)auStack_13c & 0xffffffff,uRam0000000000e97090 /* 'showVersion' */);
    func_0x007d1770(uVar7,(ulong)auStack_b0 & 0xffffffff,(ulong)auStack_13c & 0xffffffff,
                    (ulong)(param_1 + 1) & 0xffffffff);
    if (0xf < uStack_124) {
LAB_001a5b50:
      func_0x0071b0c8(uStack_138);
    }
    uStack_138 = uStack_138 & 0xffffff;
    uStack_124 = 0xf;
    uStack_128 = 0;
    if (0xf < uStack_98) {
LAB_001a5b40:
      uStack_124 = 0xf;
      uStack_128 = 0;
      func_0x0071b0c8(uStack_ac);
    }
    uStack_ac = uStack_ac & 0xffffff;
    uStack_98 = 0xf;
    uStack_9c = 0;
    uVar4 = func_0x0071c738();
    uVar13 = (ulong)auStack_104 & 0xffffffff;
    uVar11 = (ulong)auStack_120 & 0xffffffff;
    func_0x0074a310(uVar13,uVar9);
    func_0x0074a310(uVar11,uRam0000000000e97094 /* 'build' */);
    pcVar12 = (char *)(ulong)uRam0000000000e96d98;
    if (*pcVar12 == '\0') {
LAB_001a5b08:
      uVar9 = uRam0000000000e96da4;
      *(undefined4 *)(ulong)uRam0000000000e96d9c = uRam0000000000e96da0;
      *pcVar12 = '\x01';
      func_0x0071b348(uVar9);
    }
    uVar10 = uRam0000000000e96d9c;
    uVar9 = uRam0000000000e96d78;
    uStack_140 = uRam0000000000e96d9c;
    uStack_144 = uRam0000000000e97098;
    uStack_148 = uRam0000000000e9709c;
    uVar5 = func_0x0071c748(uVar4 & 0xffffffff,uVar13);
    if ((int)uVar5 != 0) {
      cVar8 = func_0x0071c758(uVar5 & 0xffffffff,uVar11);
joined_r0x001a5a64:
      if (cVar8 == '\0') {
        puVar6 = (undefined4 *)func_0x0071b0b8(0x20);
        uVar7 = uRam0000000000e96da4;
        if (*pcVar12 == '\0') {
          *(undefined4 *)(ulong)uRam0000000000e96d9c = uRam0000000000e96da0;
          *pcVar12 = '\x01';
          func_0x0071b348(uVar7);
        }
        uVar7 = uRam0000000000e96de0;
        puVar3 = (undefined4 *)((ulong)puVar6 & 0xffffffff);
        *puVar3 = uRam0000000000e96d7c;
        *(undefined1 *)(puVar3 + 5) = 0;
        puVar3[1] = uVar10;
        puVar3[3] = (int)param_1 + 4;
        puVar3[2] = 0;
        puVar3[4] = 0;
        *puVar6 = uVar7;
        puVar6[7] = 0;
        puVar6[6] = 0;
        puVar6 = (undefined4 *)func_0x0071b0b8(0x34);
        func_0x0071c768((ulong)puVar6 & 0xffffffff,uVar11,puVar3,&uStack_148);
        *puVar6 = uRam0000000000e96e00;
        uStack_150 = SUB84(puVar6,0);
        iVar1 = *(int *)(uVar5 + 8);
        if (iVar1 == 0) {
          uVar10 = *(uint *)(uVar5 + 0xc);
        }
        else {
          uVar10 = *(uint *)(uVar5 + 0xc);
          if ((uint)((int)(uVar10 - iVar1) >> 2) < (uint)(*(int *)(uVar5 + 0x10) - iVar1 >> 2)) {
            *(uint *)(uVar5 + 0xc) = uVar10 + 4;
            *(undefined4 *)(ulong)uVar10 = uStack_150;
            goto joined_r0x001a5a78;
          }
        }
        func_0x007d00e8(uVar5 + 4 & 0xffffffff,uVar10,1,&uStack_150);
      }
      goto joined_r0x001a5a78;
    }
  }
  puVar6 = (undefined4 *)func_0x0071b0b8(0x34);
  *puVar6 = uRam0000000000e96fa0;
  uVar7 = (undefined4)uVar5;
  puVar6[5] = uVar7;
  puVar6[2] = uVar7;
  puVar6[3] = uVar7;
  puVar6[4] = uVar7;
  func_0x00720ef0((ulong)(puVar6 + 6) & 0xffffffff,0,0);
  func_0x0074a020((ulong)(puVar6 + 6) & 0xffffffff,uVar13,0,0xffffffff);
  uStack_14c = (uint)puVar6;
  iVar1 = *(int *)(uVar4 + 8);
  if (iVar1 == 0) {
    uVar2 = *(uint *)(uVar4 + 0xc);
LAB_001a5e20:
    func_0x007ceaf0(uVar4 + 4 & 0xffffffff,uVar2,1,&uStack_14c);
  }
  else {
    uVar2 = *(uint *)(uVar4 + 0xc);
    if ((uint)(*(int *)(uVar4 + 0x10) - iVar1 >> 2) <= (uint)((int)(uVar2 - iVar1) >> 2))
    goto LAB_001a5e20;
    *(uint *)(uVar4 + 0xc) = uVar2 + 4;
    *(uint *)(ulong)uVar2 = uStack_14c;
  }
  uVar13 = (ulong)uStack_14c;
  cVar8 = func_0x0071c758(uStack_14c,(ulong)auStack_120 & 0xffffffff);
  if (cVar8 == '\0') {
    puVar6 = (undefined4 *)func_0x0071b0b8(0x20);
    uVar7 = uRam0000000000e96da4;
    if (*pcVar12 == '\0') {
      *(undefined4 *)(ulong)uRam0000000000e96d9c = uRam0000000000e96da0;
      *pcVar12 = '\x01';
      func_0x0071b348(uVar7);
    }
    uVar7 = uRam0000000000e96de0;
    puVar3 = (undefined4 *)((ulong)puVar6 & 0xffffffff);
    *puVar3 = uRam0000000000e96d7c;
    puVar3[1] = uVar10;
    puVar3[3] = (int)param_1 + 4;
    *(undefined1 *)(puVar3 + 5) = 0;
    puVar3[2] = 0;
    puVar3[4] = 0;
    *puVar6 = uVar7;
    puVar6[7] = 0;
    puVar6[6] = 0;
    puVar6 = (undefined4 *)func_0x0071b0b8(0x34);
    func_0x0071c768((ulong)puVar6 & 0xffffffff,(ulong)auStack_120 & 0xffffffff,puVar3,&uStack_148);
    uVar13 = uVar13 + 4 & 0xffffffff;
    *puVar6 = uRam0000000000e96e00;
    uStack_150 = SUB84(puVar6,0);
    iVar1 = *(int *)(uVar13 + 4);
    if (iVar1 == 0) {
      uVar10 = *(uint *)(uVar13 + 8);
    }
    else {
      uVar10 = *(uint *)(uVar13 + 8);
      if ((uint)((int)(uVar10 - iVar1) >> 2) < (uint)(*(int *)(uVar13 + 0xc) - iVar1 >> 2)) {
        *(uint *)(uVar13 + 8) = uVar10 + 4;
        *(undefined4 *)(ulong)uVar10 = uStack_150;
        goto joined_r0x001a5a78;
      }
    }
    func_0x007d00e8(uVar13,uVar10,1,&uStack_150);
  }
joined_r0x001a5a78:
  uStack_148 = uVar9;
  if (0xf < uStack_108) {
    func_0x0071b0c8(uStack_11c);
  }
  if (0xf < uStack_ec) {
    uStack_11c = uStack_11c & 0xffffff;
    uStack_108 = 0xf;
    uStack_10c = 0;
    func_0x0071b0c8(uStack_100);
  }
  param_1[1] = 1;
  *(undefined4 *)(param_1 + 4) = 0;
  *param_1 = 1;
  return;
}



