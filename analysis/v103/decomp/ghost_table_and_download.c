// ===== function 0x74240 =====

void FUN_00074240(ulong param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  char cVar12;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  ulong uVar6;
  undefined4 *puVar7;
  undefined1 uVar13;
  undefined4 uVar11;
  uint *puVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  ulong uVar18;
  int iVar19;
  ulong uVar20;
  ulong uVar21;
  uint uStack_220;
  undefined4 uStack_21c;
  uint uStack_218;
  int aiStack_214 [2];
  undefined4 uStack_20c;
  undefined1 auStack_204 [4];
  uint auStack_200 [5];
  uint uStack_1ec;
  undefined1 auStack_1e8 [4];
  uint auStack_1e4 [5];
  uint uStack_1d0;
  undefined1 auStack_1cc [4];
  uint auStack_1c8 [5];
  uint uStack_1b4;
  undefined1 auStack_1b0 [4];
  uint auStack_1ac [5];
  uint uStack_198;
  undefined1 auStack_194 [4];
  uint auStack_190 [4];
  uint uStack_180;
  uint uStack_17c;
  undefined1 auStack_178 [28];
  undefined1 auStack_15c [4];
  uint auStack_158 [5];
  uint uStack_144;
  undefined1 auStack_140 [4];
  uint auStack_13c [5];
  uint uStack_128;
  undefined1 auStack_124 [4];
  uint auStack_120 [5];
  uint uStack_10c;
  undefined1 auStack_108 [4];
  uint auStack_104 [4];
  uint uStack_f4;
  uint uStack_f0;
  undefined1 auStack_ec [4];
  uint auStack_e8 [5];
  uint uStack_d4;
  undefined1 auStack_d0 [4];
  uint auStack_cc [5];
  uint uStack_b8;
  undefined1 auStack_b4 [4];
  uint auStack_b0 [5];
  uint uStack_9c;
  
  uVar20 = (ulong)uRam0000000000e8f9f0;
  uVar2 = param_1 & 0xffffffff;
  iVar19 = *(int *)(uVar20 + 0xcc);
  iVar4 = *(int *)(uVar20 + 0xd0);
  *(undefined4 *)(uVar2 + 0xe880) = 0;
  if (iVar4 != iVar19) {
    *(int *)(uVar20 + 0xd0) = iVar19;
  }
  if (*(int *)(uVar20 + 0xc0) != *(int *)(uVar20 + 0xbc)) {
    *(int *)(uVar20 + 0xc0) = *(int *)(uVar20 + 0xbc);
  }
  func_0x001e9120(*(undefined4 *)(param_1 + 0x150));
  uVar18 = (ulong)*(uint *)(param_1 + 0x150);
  iVar19 = *(int *)(uVar2 + 0xbf58);
  *(undefined4 *)(uVar18 + 0x26e0) = 4;
  *(undefined4 *)(uVar18 + 0x26d8) = 9;
  *(undefined4 *)(uVar18 + 0x26e4) = 1;
  func_0x00215e70(auStack_140,iVar19 + 0x338);
  puVar5 = auStack_13c;
  if (0xf < uStack_128) {
    puVar5 = (uint *)(ulong)auStack_13c[0];
  }
  func_0x001e8010((ulong)puVar5 & 0xffffffff,aiStack_214);
  uVar1 = *(undefined4 *)(param_1 + 0x150);
  func_0x00216970(auStack_15c,*(int *)(uVar2 + 0xbf58) + 0x338);
  puVar5 = auStack_158;
  if (0xf < uStack_144) {
    puVar5 = (uint *)(ulong)auStack_158[0];
  }
  func_0x001e5bd0(uVar1,(ulong)puVar5 & 0xffffffff);
  func_0x00749fa0(auStack_15c);
  func_0x001e5c08(*(undefined4 *)(param_1 + 0x150),uStack_20c);
  uVar18 = (ulong)auStack_178 & 0xffffffff;
  func_0x0024cd60(uVar18,auStack_140);
  func_0x0076daf0(auStack_124,uVar18,uRam0000000000e926e8 /* '_basic' */);
  func_0x00749fa0(uVar18);
  puVar5 = auStack_120;
  if (0xf < uStack_10c) {
    puVar5 = (uint *)(ulong)auStack_120[0];
  }
  func_0x001e5c78(*(undefined4 *)(param_1 + 0x150),(ulong)puVar5 & 0xffffffff);
  func_0x001e59b0(*(undefined4 *)(param_1 + 0x150));
  uVar1 = uRam0000000000e926ec /* 'Time trial' */;
  uVar15 = *(uint *)(param_1 + 0x150);
  *(undefined4 *)((ulong)uVar15 + 0x26ec) = 1;
  func_0x001e5c40((ulong)uVar15,uVar1);
  func_0x001e8358(*(undefined4 *)(param_1 + 0x150));
  func_0x001e5af0(*(undefined4 *)(param_1 + 0x150),uRam0000000000e922a8 /* 'osd-timeattack.gui' */);
  uVar15 = *(uint *)(param_1 + 0x150);
  uVar18 = (ulong)uVar15 + 0x2748 & 0xffffffff;
  *(undefined1 *)((ulong)uVar15 + 0x2758) = 1;
  if (*(int *)(uVar18 + 8) != *(int *)(uVar18 + 4)) {
    *(int *)(uVar18 + 8) = *(int *)(uVar18 + 4);
  }
  piVar3 = (int *)((ulong)uVar15 + 0x274c & 0xffffffff);
  iVar19 = *piVar3;
  *piVar3 = 0;
  *(undefined4 *)(uVar18 + 0xc) = 0;
  *(undefined4 *)(uVar18 + 8) = 0;
  if (iVar19 != 0) {
    func_0x0071b0c8(iVar19);
  }
  func_0x002142e8(auStack_108,*(int *)(uVar2 + 0xbf58) + 0x338);
  uStack_17c = 0xf;
  auStack_190[0] = auStack_190[0] & 0xffffff;
  uStack_180 = 0;
  cVar12 = func_0x00720a28(auStack_194,uStack_f4,0);
  if (cVar12 != '\0') {
    puVar5 = auStack_190;
    if (0xf < uStack_17c) {
      puVar5 = (uint *)(ulong)auStack_190[0];
    }
    puVar14 = auStack_104;
    if (0xf < uStack_f0) {
      puVar14 = (uint *)(ulong)auStack_104[0];
    }
    func_0x0071b098((ulong)puVar5 & 0xffffffff,(ulong)puVar14 & 0xffffffff,uStack_f4);
    puVar5 = auStack_190;
    if (0xf < uStack_17c) {
      puVar5 = (uint *)(ulong)auStack_190[0];
    }
    uStack_180 = uStack_f4;
    *(undefined1 *)((long)puVar5 + (ulong)uStack_f4 & 0xffffffff) = 0;
  }
  uVar18 = (ulong)auStack_194 & 0xffffffff;
  func_0x00239238(auStack_ec,uVar18,*(undefined4 *)(uVar2 + 0xdad0),*(undefined4 *)(uVar2 + 0xdb00),
                  0);
  func_0x00749fa0(uVar18);
  func_0x0023ac98(auStack_d0,*(undefined4 *)(uVar2 + 0xdad0),*(undefined4 *)(uVar2 + 0xdb00),0);
  uVar1 = uRam0000000000e926f4 /* 'PlayTimeTrial' */;
  puVar5 = auStack_104;
  if (0xf < uStack_f0) {
    puVar5 = (uint *)(ulong)auStack_104[0];
  }
  puVar14 = auStack_e8;
  if (0xf < uStack_d4) {
    puVar14 = (uint *)(ulong)auStack_e8[0];
  }
  puVar16 = auStack_cc;
  if (0xf < uStack_b8) {
    puVar16 = (uint *)(ulong)auStack_cc[0];
  }
  func_0x0027c1b8(uRam0000000000e926f0 /* '%s: Vehicle class: %s, vehicle name %s, avatarName: %s' */,uRam0000000000e926f4 /* 'PlayTimeTrial' */,(ulong)puVar5 & 0xffffffff,
                  (ulong)puVar14 & 0xffffffff,(ulong)puVar16 & 0xffffffff);
  func_0x00037b20(auStack_b4,uVar2);
  uVar18 = func_0x0071b0b8(0x78);
  iVar19 = *(int *)(param_1 + 0x150);
  *(undefined4 *)((uVar18 & 0xffffffff) + 0x68) = 0;
  *(undefined4 *)((uVar18 & 0xffffffff) + 4) = 4;
  *(undefined4 *)(uVar18 + 0x70) = 0;
  uStack_220 = (uint)uVar18;
  func_0x0071b048(uVar18 + 0x28 & 0xffffffff,iVar19 + 0x23d0);
  puVar5 = auStack_e8;
  if (0xf < uStack_d4) {
    puVar5 = (uint *)(ulong)auStack_e8[0];
  }
  func_0x0071b048(uStack_220 + 8,(ulong)puVar5 & 0xffffffff);
  puVar5 = auStack_cc;
  if (0xf < uStack_b8) {
    puVar5 = (uint *)(ulong)auStack_cc[0];
  }
  func_0x0071b048(uStack_220 + 0x48,(ulong)puVar5 & 0xffffffff);
  uVar15 = uStack_220;
  uVar8 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(uVar2 + 0xdacc
                                                                                     ) + 0x20))
                    ((uint *)(ulong)*(uint *)(uVar2 + 0xdacc),0);
  *(undefined4 *)((ulong)uVar15 + 0x6c) = uVar8;
  *(undefined1 *)(ulong)uStack_220 = 0;
  uVar8 = uRam0000000000e91ba4 /* 'Local' */;
  puVar5 = auStack_b0;
  if (0xf < uStack_9c) {
    puVar5 = (uint *)(ulong)auStack_b0[0];
  }
  puVar14 = auStack_e8;
  if (0xf < uStack_d4) {
    puVar14 = (uint *)(ulong)auStack_e8[0];
  }
  puVar16 = auStack_cc;
  if (0xf < uStack_b8) {
    puVar16 = (uint *)(ulong)auStack_cc[0];
  }
  func_0x001e6978(*(undefined4 *)(param_1 + 0x150),(ulong)puVar5 & 0xffffffff,
                  (ulong)puVar14 & 0xffffffff,(ulong)puVar16 & 0xffffffff,uRam0000000000e92064 /* 'Human' */,
                  uRam0000000000e91ba4 /* 'Local' */,0,0xffffffffffffffff);
  uStack_218 = uStack_220;
  uVar18 = (ulong)*(uint *)(param_1 + 0x150) + 0x2748 & 0xffffffff;
  iVar19 = *(int *)(uVar18 + 4);
  if ((iVar19 == 0) ||
     (uVar15 = *(uint *)(uVar18 + 8),
     (uint)(*(int *)(uVar18 + 0xc) - iVar19 >> 2) <= (uint)((int)(uVar15 - iVar19) >> 2))) {
    func_0x0074f478(uVar18,*(undefined4 *)(uVar18 + 8),1,&uStack_218);
  }
  else {
    *(uint *)(uVar18 + 8) = uVar15 + 4;
    *(uint *)(ulong)uVar15 = uStack_220;
  }
  uVar18 = func_0x0071b0b8(0x78);
  iVar19 = *(int *)(param_1 + 0x150);
  *(undefined4 *)((uVar18 & 0xffffffff) + 0x68) = 0;
  *(undefined4 *)((uVar18 & 0xffffffff) + 4) = 3;
  *(undefined4 *)(uVar18 + 0x70) = 0;
  uStack_220 = (uint)uVar18;
  func_0x0071b048(uVar18 + 0x28 & 0xffffffff,iVar19 + 0x23d0);
  puVar5 = auStack_e8;
  if (0xf < uStack_d4) {
    puVar5 = (uint *)(ulong)auStack_e8[0];
  }
  func_0x0071b048(uStack_220 + 8,(ulong)puVar5 & 0xffffffff);
  puVar5 = auStack_cc;
  if (0xf < uStack_b8) {
    puVar5 = (uint *)(ulong)auStack_cc[0];
  }
  func_0x0071b048(uStack_220 + 0x48,(ulong)puVar5 & 0xffffffff);
  uVar15 = uStack_220;
  uVar9 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(uVar2 + 0xdacc
                                                                                     ) + 0x20))
                    ((uint *)(ulong)*(uint *)(uVar2 + 0xdacc),1);
  puVar5 = auStack_b0;
  *(undefined4 *)((ulong)uVar15 + 0x6c) = uVar9;
  *(undefined1 *)(ulong)uStack_220 = 0;
  uVar9 = uRam0000000000e926f8 /* 'Ghost' */;
  if (0xf < uStack_9c) {
    puVar5 = (uint *)(ulong)auStack_b0[0];
  }
  puVar14 = auStack_e8;
  if (0xf < uStack_d4) {
    puVar14 = (uint *)(ulong)auStack_e8[0];
  }
  puVar16 = auStack_cc;
  if (0xf < uStack_b8) {
    puVar16 = (uint *)(ulong)auStack_cc[0];
  }
  func_0x001e6978(*(undefined4 *)(param_1 + 0x150),(ulong)puVar5 & 0xffffffff,
                  (ulong)puVar14 & 0xffffffff,(ulong)puVar16 & 0xffffffff,uRam0000000000e926f8 /* 'Ghost' */,uVar8
                  ,0xffffffffffffffff,0xffffffffffffffff);
  uStack_218 = uStack_220;
  uVar18 = (ulong)*(uint *)(param_1 + 0x150) + 0x2748 & 0xffffffff;
  iVar19 = *(int *)(uVar18 + 4);
  if ((iVar19 == 0) ||
     (uVar15 = *(uint *)(uVar18 + 8),
     (uint)(*(int *)(uVar18 + 0xc) - iVar19 >> 2) <= (uint)((int)(uVar15 - iVar19) >> 2))) {
    func_0x0074f478(uVar18,*(undefined4 *)(uVar18 + 8),1,&uStack_218);
  }
  else {
    *(uint *)(uVar18 + 8) = uVar15 + 4;
    *(uint *)(ulong)uVar15 = uStack_220;
  }
  uVar10 = func_0x0071b0b8(0x18);
  func_0x0020a710(uVar10);
  iVar19 = 2;
  uVar18 = 0;
  do {
    while (uVar10 = (undefined4)param_1,
          *(int *)((ulong)*(uint *)(uVar2 + 0xbf58) +
                   (long)((int)((uVar18 & 0xffffffff) << 2) + 0x660) + 0x10) != 4) {
      uVar18 = uVar18 + 1;
      if (uVar18 == 8) goto LAB_000749b0;
    }
    func_0x0027c1b8(uRam0000000000e926fc /* '%s: Adding profile ghost #%d' */,uVar1,uVar18 & 0xffffffff);
    func_0x002395c0(auStack_204,(long)(int)uVar18,*(undefined4 *)(uVar2 + 0xdad0),
                    *(undefined4 *)(uVar2 + 0xdb00),0);
    uVar21 = func_0x0071b0b8(0x78);
    iVar4 = *(int *)(param_1 + 0x150);
    *(undefined4 *)((uVar21 & 0xffffffff) + 4) = 0;
    *(int *)((uVar21 & 0xffffffff) + 0x68) = (int)uVar18;
    *(undefined4 *)(uVar21 + 0x70) = 0;
    uStack_220 = (uint)uVar21;
    func_0x0071b048(uVar21 + 0x28 & 0xffffffff,iVar4 + 0x23d0);
    if (uStack_1ec < 0x10) {
      uVar21 = (ulong)auStack_200 & 0xffffffff;
    }
    else {
      uVar21 = (ulong)auStack_200[0];
    }
    func_0x0071b048(uStack_220 + 8,uVar21);
    if (uStack_b8 < 0x10) {
      uVar21 = (ulong)auStack_cc & 0xffffffff;
    }
    else {
      uVar21 = (ulong)auStack_cc[0];
    }
    func_0x0071b048(uStack_220 + 0x48,uVar21);
    uVar15 = uStack_220;
    uVar11 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(uVar2 + 
                                                  0xdacc) + 0x20))
                       ((uint *)(ulong)*(uint *)(uVar2 + 0xdacc),iVar19);
    *(undefined4 *)((ulong)uVar15 + 0x6c) = uVar11;
    *(undefined1 *)(ulong)uStack_220 = 0;
    func_0x00037b20(auStack_1e8,uVar2);
    if (uStack_1d0 < 0x10) {
      puVar5 = auStack_1e4;
      if (0xf < uStack_1ec) goto LAB_000751a0;
LAB_000754f8:
      puVar14 = auStack_200;
      if (0xf < uStack_b8) goto LAB_000751b0;
LAB_00075508:
      uVar21 = (ulong)auStack_cc & 0xffffffff;
    }
    else {
      puVar5 = (uint *)(ulong)auStack_1e4[0];
      if (uStack_1ec < 0x10) goto LAB_000754f8;
LAB_000751a0:
      puVar14 = (uint *)(ulong)auStack_200[0];
      if (uStack_b8 < 0x10) goto LAB_00075508;
LAB_000751b0:
      uVar21 = (ulong)auStack_cc[0];
    }
    uStack_21c = func_0x001e6978(*(undefined4 *)(param_1 + 0x150),(ulong)puVar5 & 0xffffffff,
                                 (ulong)puVar14 & 0xffffffff,uVar21,uVar9,uVar8,0xffffffffffffffff,
                                 0xffffffffffffffff);
    uVar21 = (ulong)*(uint *)(param_1 + 0x150) + 0x2748 & 0xffffffff;
    uStack_218 = uStack_220;
    iVar4 = *(int *)(uVar21 + 4);
    if ((iVar4 == 0) ||
       (uVar15 = *(uint *)(uVar21 + 8),
       (uint)(*(int *)(uVar21 + 0xc) - iVar4 >> 2) <= (uint)((int)(uVar15 - iVar4) >> 2))) {
      func_0x0074f478(uVar21,*(undefined4 *)(uVar21 + 8),1,&uStack_218);
      iVar4 = *(int *)(uVar20 + 0xcc);
      if (iVar4 == 0) goto LAB_000753fc;
      uVar15 = *(uint *)(uVar20 + 0xd0);
      iVar17 = uVar15 - iVar4;
      iVar4 = *(int *)(uVar20 + 0xd4) - iVar4;
LAB_0007524c:
      if ((uint)(iVar4 >> 2) <= (uint)(iVar17 >> 2)) goto LAB_00075400;
      iVar4 = *(int *)(uVar20 + 0xbc);
      *(uint *)(uVar20 + 0xd0) = uVar15 + 4;
      *(undefined4 *)(ulong)uVar15 = uStack_21c;
      if (iVar4 == 0) goto LAB_000753d4;
      uVar15 = *(uint *)(uVar20 + 0xc0);
      iVar17 = uVar15 - iVar4;
      iVar4 = *(int *)(uVar20 + 0xc4) - iVar4;
LAB_00075290:
      puVar5 = (uint *)(ulong)uVar15;
      if ((uint)(iVar4 >> 2) <= (uint)(iVar17 >> 2)) goto LAB_000753d8;
      *(uint *)(uVar20 + 0xc0) = uVar15 + 4;
      *puVar5 = uStack_220;
      puVar7 = (undefined4 *)func_0x0071b0b8(0x18);
    }
    else {
      iVar4 = *(int *)(uVar20 + 0xcc);
      *(uint *)(uVar21 + 8) = uVar15 + 4;
      *(uint *)(ulong)uVar15 = uStack_220;
      if (iVar4 != 0) {
        uVar15 = *(uint *)(uVar20 + 0xd0);
        iVar17 = uVar15 - iVar4;
        iVar4 = *(int *)(uVar20 + 0xd4) - iVar4;
        goto LAB_0007524c;
      }
LAB_000753fc:
      uVar15 = *(uint *)(uVar20 + 0xd0);
LAB_00075400:
      func_0x00757120(uVar20 + 200,uVar15,1,&uStack_21c);
      iVar4 = *(int *)(uVar20 + 0xbc);
      if (iVar4 != 0) {
        uVar15 = *(uint *)(uVar20 + 0xc0);
        iVar17 = uVar15 - iVar4;
        iVar4 = *(int *)(uVar20 + 0xc4) - iVar4;
        goto LAB_00075290;
      }
LAB_000753d4:
      puVar5 = (uint *)(ulong)*(uint *)(uVar20 + 0xc0);
LAB_000753d8:
      func_0x0074f478(uVar20 + 0xb8,puVar5,1,&uStack_220);
      puVar7 = (undefined4 *)func_0x0071b0b8(0x18);
    }
    func_0x0020a710((ulong)puVar7 & 0xffffffff);
    *puVar7 = 1;
    puVar7[1] = 0;
    puVar7[2] = uStack_220;
    uVar13 = func_0x001e5220((long)aiStack_214[0]);
    uVar11 = uRam0000000000e92700;
    *(undefined1 *)(puVar7 + 3) = uVar13;
    puVar7[4] = uVar10;
    puVar7[5] = uVar11;
    func_0x0021b5a8(*(int *)(uVar2 + 0xbf58) + 0x338,(ulong)puVar7 & 0xffffffff);
    uVar18 = uVar18 + 1;
    iVar19 = iVar19 + 1;
    *(int *)(uVar2 + 0xe880) = *(int *)(uVar2 + 0xe880) + 1;
    func_0x00749fa0(auStack_1e8);
    func_0x00749fa0(auStack_204);
  } while (uVar18 != 8);
LAB_000749b0:
  uVar18 = 0;
  do {
    while (*(int *)((ulong)*(uint *)(uVar2 + 0xbf58) +
                    (long)((int)((uVar18 & 0xffffffff) << 2) + 0x680) + 0x10) != 4) {
      uVar18 = uVar18 + 1;
      if (uVar18 == 8) goto LAB_000749ec;
    }
    func_0x0027c1b8(uRam0000000000e92704 /* '%s: Adding dev ghost #%d' */,uVar1,uVar18 & 0xffffffff);
    uVar21 = func_0x0071b0b8(0x78);
    iVar4 = *(int *)(param_1 + 0x150);
    *(undefined4 *)(uVar21 + 0x70) = 0;
    *(undefined4 *)((uVar21 & 0xffffffff) + 4) = 1;
    *(int *)((uVar21 & 0xffffffff) + 0x68) = (int)uVar18;
    uStack_220 = (uint)uVar21;
    func_0x0071b048(uVar21 + 0x28 & 0xffffffff,iVar4 + 0x23d0);
    if (uStack_d4 < 0x10) {
      uVar21 = (ulong)auStack_e8 & 0xffffffff;
    }
    else {
      uVar21 = (ulong)auStack_e8[0];
    }
    func_0x0071b048(uStack_220 + 8,uVar21);
    if (uStack_b8 < 0x10) {
      uVar21 = (ulong)auStack_cc & 0xffffffff;
    }
    else {
      uVar21 = (ulong)auStack_cc[0];
    }
    func_0x0071b048(uStack_220 + 0x48,uVar21);
    uVar15 = uStack_220;
    uVar8 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(uVar2 + 
                                                  0xdacc) + 0x20))
                      ((uint *)(ulong)*(uint *)(uVar2 + 0xdacc),iVar19);
    iVar4 = *(int *)(uVar2 + 0xbf58);
    *(undefined4 *)((ulong)uVar15 + 0x6c) = uVar8;
    *(undefined1 *)(ulong)uStack_220 = 0;
    func_0x00218470(auStack_1b0,iVar4 + 0x338,2,(long)(int)uVar18);
    if (uStack_198 < 0x10) {
      puVar5 = auStack_1ac;
      if (0xf < uStack_b8) goto LAB_00074ec8;
LAB_000755a0:
      uVar21 = (ulong)auStack_cc & 0xffffffff;
    }
    else {
      puVar5 = (uint *)(ulong)auStack_1ac[0];
      if (uStack_b8 < 0x10) goto LAB_000755a0;
LAB_00074ec8:
      uVar21 = (ulong)auStack_cc[0];
    }
    uStack_21c = func_0x001e6978(*(undefined4 *)(param_1 + 0x150),(ulong)puVar5 & 0xffffffff,
                                 uRam0000000000e903bc,uVar21,uVar9,uRam0000000000e92708,
                                 0xffffffffffffffff,0xffffffffffffffff);
    uVar21 = (ulong)*(uint *)(param_1 + 0x150) + 0x2748 & 0xffffffff;
    uStack_218 = uStack_220;
    iVar4 = *(int *)(uVar21 + 4);
    if ((iVar4 == 0) ||
       (uVar15 = *(uint *)(uVar21 + 8),
       (uint)(*(int *)(uVar21 + 0xc) - iVar4 >> 2) <= (uint)((int)(uVar15 - iVar4) >> 2))) {
      func_0x0074f478(uVar21,*(undefined4 *)(uVar21 + 8),1,&uStack_218);
      iVar4 = *(int *)(uVar20 + 0xcc);
      if (iVar4 != 0) goto LAB_00074f50;
LAB_00075380:
      uVar15 = *(uint *)(uVar20 + 0xd0);
LAB_00075388:
      func_0x00757120(uVar20 + 200,uVar15,1,&uStack_21c);
      iVar4 = *(int *)(uVar20 + 0xbc);
      if (iVar4 == 0) goto LAB_000753ac;
LAB_00074f94:
      uVar15 = *(uint *)(uVar20 + 0xc0);
      if ((uint)(*(int *)(uVar20 + 0xc4) - iVar4 >> 2) <= (uint)((int)(uVar15 - iVar4) >> 2))
      goto LAB_000753b0;
      *(uint *)(uVar20 + 0xc0) = uVar15 + 4;
      *(uint *)(ulong)uVar15 = uStack_220;
      puVar7 = (undefined4 *)func_0x0071b0b8(0x18);
    }
    else {
      iVar4 = *(int *)(uVar20 + 0xcc);
      *(uint *)(uVar21 + 8) = uVar15 + 4;
      *(uint *)(ulong)uVar15 = uStack_220;
      if (iVar4 == 0) goto LAB_00075380;
LAB_00074f50:
      uVar15 = *(uint *)(uVar20 + 0xd0);
      if ((uint)(*(int *)(uVar20 + 0xd4) - iVar4 >> 2) <= (uint)((int)(uVar15 - iVar4) >> 2))
      goto LAB_00075388;
      iVar4 = *(int *)(uVar20 + 0xbc);
      *(uint *)(uVar20 + 0xd0) = uVar15 + 4;
      *(undefined4 *)(ulong)uVar15 = uStack_21c;
      if (iVar4 != 0) goto LAB_00074f94;
LAB_000753ac:
      uVar15 = *(uint *)(uVar20 + 0xc0);
LAB_000753b0:
      func_0x0074f478(uVar20 + 0xb8,uVar15,1,&uStack_220);
      puVar7 = (undefined4 *)func_0x0071b0b8(0x18);
    }
    func_0x0020a710((ulong)puVar7 & 0xffffffff);
    puVar7[2] = uStack_220;
    *puVar7 = 1;
    puVar7[1] = 0;
    uVar13 = func_0x001e5220((long)aiStack_214[0]);
    uVar8 = uRam0000000000e92700;
    *(undefined1 *)(puVar7 + 3) = uVar13;
    puVar7[4] = uVar10;
    puVar7[5] = uVar8;
    func_0x0021b5a8(*(int *)(uVar2 + 0xbf58) + 0x338,(ulong)puVar7 & 0xffffffff);
    uVar18 = uVar18 + 1;
    iVar19 = iVar19 + 1;
    *(int *)(uVar2 + 0xe880) = *(int *)(uVar2 + 0xe880) + 1;
    func_0x00749fa0(auStack_1b0);
  } while (uVar18 != 8);
LAB_000749ec:
  uVar21 = 0;
  uVar18 = (ulong)uRam0000000000e91ce0;
  do {
    while (*(int *)((ulong)*(uint *)(uVar2 + 0xbf58) +
                    (long)((int)((uVar21 & 0xffffffff) << 2) + 0x6a0) + 0x10) != 4) {
      uVar21 = uVar21 + 1;
      uVar18 = uVar18 + 4;
      if (uVar21 == 8) goto LAB_00074a30;
    }
    func_0x0027c1b8(uRam0000000000e9270c /* '%s: Adding online ghost #%d' */,uVar1,uVar21 & 0xffffffff);
    uVar6 = func_0x0071b0b8(0x78);
    iVar4 = *(int *)(param_1 + 0x150);
    *(undefined4 *)((uVar6 & 0xffffffff) + 4) = 2;
    *(undefined4 *)(uVar6 + 0x70) = 0;
    *(int *)((uVar6 & 0xffffffff) + 0x68) = (int)uVar21;
    uStack_220 = (uint)uVar6;
    func_0x0071b048(uVar6 + 0x28 & 0xffffffff,iVar4 + 0x23d0);
    func_0x0071b048(uStack_220 + 8,*(undefined4 *)(uVar18 & 0xffffffff));
    if (uStack_b8 < 0x10) {
      uVar6 = (ulong)auStack_cc & 0xffffffff;
    }
    else {
      uVar6 = (ulong)auStack_cc[0];
    }
    func_0x0071b048(uStack_220 + 0x48,uVar6);
    uVar15 = uStack_220;
    uVar8 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(uVar2 + 
                                                  0xdacc) + 0x20))
                      ((uint *)(ulong)*(uint *)(uVar2 + 0xdacc),iVar19);
    iVar4 = *(int *)(uVar2 + 0xbf58);
    *(undefined4 *)((ulong)uVar15 + 0x6c) = uVar8;
    *(undefined1 *)(ulong)uStack_220 = 0;
    func_0x00218470(auStack_1cc,iVar4 + 0x338,1,(long)(int)uVar21);
    if (uStack_1b4 < 0x10) {
      puVar5 = auStack_1c8;
      if (0xf < uStack_b8) goto LAB_00074bf0;
LAB_00075560:
      uVar6 = (ulong)auStack_cc & 0xffffffff;
    }
    else {
      puVar5 = (uint *)(ulong)auStack_1c8[0];
      if (uStack_b8 < 0x10) goto LAB_00075560;
LAB_00074bf0:
      uVar6 = (ulong)auStack_cc[0];
    }
    uStack_21c = func_0x001e6978(*(undefined4 *)(param_1 + 0x150),(ulong)puVar5 & 0xffffffff,
                                 uRam0000000000e903bc,uVar6,uVar9,uRam0000000000e911f8 /* 'Online' */,
                                 0xffffffffffffffff,0xffffffffffffffff);
    uVar6 = (ulong)*(uint *)(param_1 + 0x150) + 0x2748 & 0xffffffff;
    uStack_218 = uStack_220;
    iVar4 = *(int *)(uVar6 + 4);
    if ((iVar4 == 0) ||
       (uVar15 = *(uint *)(uVar6 + 8),
       (uint)(*(int *)(uVar6 + 0xc) - iVar4 >> 2) <= (uint)((int)(uVar15 - iVar4) >> 2))) {
      func_0x0074f478(uVar6,*(undefined4 *)(uVar6 + 8),1,&uStack_218);
      iVar4 = *(int *)(uVar20 + 0xcc);
      if (iVar4 != 0) goto LAB_00074c7c;
LAB_00075494:
      uVar15 = *(uint *)(uVar20 + 0xd0);
LAB_00075498:
      func_0x00757120(uVar20 + 200,uVar15,1,&uStack_21c);
      iVar4 = *(int *)(uVar20 + 0xbc);
      if (iVar4 == 0) goto LAB_000754bc;
LAB_00074cc0:
      uVar15 = *(uint *)(uVar20 + 0xc0);
      if ((uint)(*(int *)(uVar20 + 0xc4) - iVar4 >> 2) <= (uint)((int)(uVar15 - iVar4) >> 2))
      goto LAB_000754c0;
      *(uint *)(uVar20 + 0xc0) = uVar15 + 4;
      *(uint *)(ulong)uVar15 = uStack_220;
      puVar7 = (undefined4 *)func_0x0071b0b8(0x18);
    }
    else {
      iVar4 = *(int *)(uVar20 + 0xcc);
      *(uint *)(uVar6 + 8) = uVar15 + 4;
      *(uint *)(ulong)uVar15 = uStack_220;
      if (iVar4 == 0) goto LAB_00075494;
LAB_00074c7c:
      uVar15 = *(uint *)(uVar20 + 0xd0);
      if ((uint)(*(int *)(uVar20 + 0xd4) - iVar4 >> 2) <= (uint)((int)(uVar15 - iVar4) >> 2))
      goto LAB_00075498;
      iVar4 = *(int *)(uVar20 + 0xbc);
      *(uint *)(uVar20 + 0xd0) = uVar15 + 4;
      *(undefined4 *)(ulong)uVar15 = uStack_21c;
      if (iVar4 != 0) goto LAB_00074cc0;
LAB_000754bc:
      uVar15 = *(uint *)(uVar20 + 0xc0);
LAB_000754c0:
      func_0x0074f478(uVar20 + 0xb8,uVar15,1,&uStack_220);
      puVar7 = (undefined4 *)func_0x0071b0b8(0x18);
    }
    func_0x0020a710((ulong)puVar7 & 0xffffffff);
    *puVar7 = 1;
    puVar7[1] = 0;
    puVar7[2] = uStack_220;
    uVar13 = func_0x001e5220((long)aiStack_214[0]);
    uVar8 = uRam0000000000e92700;
    *(undefined1 *)(puVar7 + 3) = uVar13;
    puVar7[4] = uVar10;
    puVar7[5] = uVar8;
    func_0x0021b5a8(*(int *)(uVar2 + 0xbf58) + 0x338,(ulong)puVar7 & 0xffffffff);
    uVar21 = uVar21 + 1;
    iVar19 = iVar19 + 1;
    *(int *)(uVar2 + 0xe880) = *(int *)(uVar2 + 0xe880) + 1;
    func_0x00749fa0(auStack_1cc);
    uVar18 = uVar18 + 4;
  } while (uVar21 != 8);
LAB_00074a30:
  func_0x00749fa0(auStack_b4);
  func_0x00749fa0(auStack_d0);
  func_0x00749fa0(auStack_ec);
  func_0x00749fa0(auStack_108);
  func_0x00749fa0(auStack_124);
  func_0x00749fa0(auStack_140);
  return;
}



// ===== function 0x8df98 =====

void FUN_0008df98(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar12;
  int iVar10;
  uint *puVar6;
  ulong uVar7;
  undefined4 uVar11;
  long lVar8;
  undefined4 *puVar9;
  undefined1 uVar13;
  uint *puVar14;
  ulong uVar15;
  ulong uVar16;
  uint uVar17;
  undefined1 auStack_100 [4];
  uint auStack_fc [4];
  uint uStack_ec;
  uint uStack_e8;
  undefined1 auStack_e4 [4];
  uint uStack_e0;
  undefined4 uStack_d0;
  uint uStack_cc;
  undefined1 auStack_c8 [4];
  uint auStack_c4 [4];
  uint uStack_b4;
  uint uStack_b0;
  undefined1 auStack_ac [4];
  uint auStack_a8 [4];
  uint uStack_98;
  uint uStack_94;
  undefined1 auStack_90 [4];
  uint uStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  
  puVar14 = (uint *)(ulong)uRam0000000000e8fa0c;
  cVar12 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar14 + 0xd38))
                     ((uint *)(ulong)*puVar14);
  if (cVar12 == '\0') {
    return;
  }
  uVar16 = 0;
  uVar1 = *(uint *)(ulong)uRam0000000000e92aa0;
  iVar10 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar14 + 0xd80))
                     ((uint *)(ulong)*puVar14);
  uStack_98 = 0;
  uVar7 = (ulong)(iVar10 + 0x10U);
  uStack_94 = 0xf;
  auStack_a8[0] = auStack_a8[0] & 0xffffff;
  uVar17 = *(uint *)(uVar7 + 0x14);
  uVar15 = (ulong)uVar17;
  if (iVar10 + 0x10U == (uint)auStack_ac) {
    if (uVar15 != 0) {
      func_0x0071b0a8(uVar7);
      uVar16 = (ulong)uStack_98;
    }
    iVar10 = (int)(uVar16 - uVar15);
    if ((iVar10 == -1) || (iVar10 != 0)) {
      lVar8 = uVar16 - (uVar16 - uVar15);
      puVar6 = auStack_a8;
      if (0xf < uStack_94) {
        puVar6 = (uint *)(ulong)auStack_a8[0];
      }
      uStack_98 = (uint)lVar8;
      *(undefined1 *)((long)puVar6 + lVar8 & 0xffffffff) = 0;
    }
LAB_0008e140:
    if (0xf < uStack_94) {
LAB_0008e860:
      func_0x0071b0c8(auStack_a8[0]);
    }
    auStack_a8[0] = auStack_a8[0] & 0xffffff;
    uStack_94 = 0xf;
    uStack_98 = 0;
    iVar10 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar14 + 0xd80))();
    uVar17 = iVar10 + 0x10;
    uVar7 = (ulong)uVar17;
    auStack_fc[0] = auStack_fc[0] & 0xffffff;
    uVar15 = (ulong)*(uint *)(uVar7 + 0x14);
    if (uVar17 != (uint)auStack_100) goto LAB_0008e1ac;
LAB_0008e5f8:
    uStack_e8 = 0xf;
    uStack_ec = 0;
    uVar16 = 0;
    if (uVar15 != 0) {
      func_0x0071b0a8(uVar7);
      uVar16 = (ulong)uStack_ec;
    }
    iVar10 = (int)(uVar16 - uVar15);
    if ((iVar10 == -1) || (iVar10 != 0)) {
      lVar8 = uVar16 - (uVar16 - uVar15);
      puVar6 = auStack_fc;
      if (0xf < uStack_e8) {
        puVar6 = (uint *)(ulong)auStack_fc[0];
      }
      uStack_ec = (uint)lVar8;
      *(undefined1 *)((long)puVar6 + lVar8 & 0xffffffff) = 0;
    }
LAB_0008e640:
    if (0xf < uStack_e8) goto LAB_0008e1d8;
LAB_0008e648:
    func_0x0027c1b8(uRam0000000000e92aa4 /* 'Checking for downloaded ghost for account %s' */,(ulong)auStack_fc & 0xffffffff);
  }
  else {
    cVar12 = func_0x00720a28(auStack_ac,uVar17,0);
    if (cVar12 != '\0') {
      puVar6 = auStack_a8;
      if (0xf < uStack_94) {
        puVar6 = (uint *)(ulong)auStack_a8[0];
      }
      if (*(uint *)(uVar7 + 0x18) < 0x10) {
        iVar10 = iVar10 + 0x14;
      }
      else {
        iVar10 = *(int *)(uVar7 + 4);
      }
      func_0x0071b098((ulong)puVar6 & 0xffffffff,iVar10,uVar17);
      puVar6 = auStack_a8;
      if (0xf < uStack_94) {
        puVar6 = (uint *)(ulong)auStack_a8[0];
      }
      *(undefined1 *)((long)puVar6 + uVar15 & 0xffffffff) = 0;
      uStack_98 = uVar17;
      goto LAB_0008e140;
    }
    if (0xf < uStack_94) goto LAB_0008e860;
    auStack_a8[0] = auStack_a8[0] & 0xffffff;
    uStack_98 = 0;
    uStack_94 = 0xf;
    iVar10 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar14 + 0xd80))
                       ((uint *)(ulong)*puVar14);
    uVar17 = iVar10 + 0x10;
    uVar7 = (ulong)uVar17;
    auStack_fc[0] = auStack_fc[0] & 0xffffff;
    uVar15 = (ulong)*(uint *)(uVar7 + 0x14);
    if (uVar17 == (uint)auStack_100) goto LAB_0008e5f8;
LAB_0008e1ac:
    uStack_e8 = 0xf;
    uStack_ec = 0;
    cVar12 = func_0x00720a28(auStack_100,uVar15,0);
    if (cVar12 != '\0') {
      puVar6 = auStack_fc;
      if (0xf < uStack_e8) {
        puVar6 = (uint *)(ulong)auStack_fc[0];
      }
      if (*(uint *)(uVar7 + 0x18) < 0x10) {
        iVar10 = uVar17 + 4;
      }
      else {
        iVar10 = *(int *)(uVar7 + 4);
      }
      func_0x0071b098((ulong)puVar6 & 0xffffffff,iVar10,uVar15);
      puVar6 = auStack_fc;
      if (0xf < uStack_e8) {
        puVar6 = (uint *)(ulong)auStack_fc[0];
      }
      uStack_ec = (uint)uVar15;
      *(undefined1 *)((long)puVar6 + uVar15 & 0xffffffff) = 0;
      goto LAB_0008e640;
    }
    if (uStack_e8 < 0x10) goto LAB_0008e648;
LAB_0008e1d8:
    func_0x0027c1b8(uRam0000000000e92aa4 /* 'Checking for downloaded ghost for account %s' */,auStack_fc[0]);
  }
  if (0xf < uStack_e8) {
    func_0x0071b0c8(auStack_fc[0]);
  }
  auStack_fc[0] = auStack_fc[0] & 0xffffff;
  uStack_e8 = 0xf;
  uStack_ec = 0;
  if (uVar1 == 0) {
    func_0x0027c1b8(uRam0000000000e92ab0 /* 'No downloaded ghost available' */);
    return;
  }
  uVar7 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar14 + 0xd80))
                    ((uint *)(ulong)*puVar14);
  uVar2 = *(undefined4 *)((uVar7 & 0xffffffff) + 4);
  iVar10 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar14 + 0xd80))
                     ((uint *)(ulong)*puVar14);
  uVar15 = 0;
  uStack_b4 = 0;
  uVar7 = (ulong)(iVar10 + 0x10U);
  uStack_b0 = 0xf;
  auStack_c4[0] = auStack_c4[0] & 0xffffff;
  uVar17 = *(uint *)(uVar7 + 0x14);
  uVar16 = (ulong)uVar17;
  if (iVar10 + 0x10U == (uint)auStack_c8) {
    if (uVar16 != 0) {
      func_0x0071b0a8(uVar7);
      uVar15 = (ulong)uStack_b4;
    }
    iVar10 = (int)(uVar15 - uVar16);
    if ((iVar10 == -1) || (iVar10 != 0)) {
      lVar8 = uVar15 - (uVar15 - uVar16);
      puVar6 = auStack_c4;
      if (0xf < uStack_b0) {
        puVar6 = (uint *)(ulong)auStack_c4[0];
      }
      uStack_b4 = (uint)lVar8;
      *(undefined1 *)((long)puVar6 + lVar8 & 0xffffffff) = 0;
    }
  }
  else {
    cVar12 = func_0x00720a28(auStack_c8,uVar17,0);
    if (cVar12 != '\0') {
      puVar6 = auStack_c4;
      if (0xf < uStack_b0) {
        puVar6 = (uint *)(ulong)auStack_c4[0];
      }
      if (*(uint *)(uVar7 + 0x18) < 0x10) {
        iVar10 = iVar10 + 0x14;
      }
      else {
        iVar10 = *(int *)(uVar7 + 4);
      }
      func_0x0071b098((ulong)puVar6 & 0xffffffff,iVar10,uVar17);
      uStack_b4 = uVar17;
      if (0xf < uStack_b0) {
        uVar7 = (ulong)uVar1;
        *(undefined1 *)(auStack_c4[0] + uVar16 & 0xffffffff) = 0;
        iVar10 = func_0x0021e838(uVar7);
        func_0x0074a310((ulong)auStack_e4 & 0xffffffff,iVar10 + 0x48);
        iVar10 = func_0x0021e838(uVar7);
        func_0x0074a310((ulong)auStack_90 & 0xffffffff,iVar10 + 8);
        uVar15 = (ulong)param_1;
        uVar7 = (ulong)*(uint *)(uVar7 + 0x10);
        uVar3 = *(undefined4 *)(uVar7 + 0x90);
        uVar4 = *(undefined4 *)(uVar7 + 0x98);
        uVar5 = *(undefined4 *)(uVar7 + 0x94);
        uVar11 = func_0x0020a848(*(int *)(uVar15 + 0xbf58) + 0x338);
        iVar10 = *(int *)(uVar15 + 0xbf58);
        uVar7 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar14 + 0xd80))
                          ((uint *)(ulong)*puVar14);
        func_0x00213b08(iVar10 + 0x338,*(undefined4 *)(uVar7 & 0xffffffff));
        func_0x002167c0(*(int *)(uVar15 + 0xbf58) + 0x338,uVar2,auStack_c8,
                        (ulong)auStack_e4 & 0xffffffff,(ulong)auStack_90 & 0xffffffff,uVar5,uVar4,
                        uVar3,uVar3);
        func_0x00213a80(*(int *)(uVar15 + 0xbf58) + 0x338,uVar11);
        goto LAB_0008e428;
      }
      *(undefined1 *)((long)auStack_c4 + uVar16 & 0xffffffff) = 0;
    }
  }
  uVar7 = (ulong)uVar1;
  iVar10 = func_0x0021e838(uVar7);
  func_0x0074a310((ulong)auStack_e4 & 0xffffffff,iVar10 + 0x48);
  iVar10 = func_0x0021e838(uVar7);
  func_0x0074a310((ulong)auStack_90 & 0xffffffff,iVar10 + 8);
  uVar15 = (ulong)param_1;
  uVar7 = (ulong)*(uint *)(uVar7 + 0x10);
  uVar3 = *(undefined4 *)(uVar7 + 0x98);
  uVar4 = *(undefined4 *)(uVar7 + 0x90);
  uVar5 = *(undefined4 *)(uVar7 + 0x94);
  uVar11 = func_0x0020a848(*(int *)(uVar15 + 0xbf58) + 0x338);
  iVar10 = *(int *)(uVar15 + 0xbf58);
  uVar7 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar14 + 0xd80))
                    ((uint *)(ulong)*puVar14);
  func_0x00213b08(iVar10 + 0x338,*(undefined4 *)(uVar7 & 0xffffffff));
  func_0x002167c0(*(int *)(uVar15 + 0xbf58) + 0x338,uVar2,auStack_c8,(ulong)auStack_e4 & 0xffffffff,
                  (ulong)auStack_90 & 0xffffffff,uVar5,uVar3,uVar4,uVar4);
  func_0x00213a80(*(int *)(uVar15 + 0xbf58) + 0x338,uVar11);
LAB_0008e428:
  lVar8 = func_0x0021e838((ulong)uVar1);
  uVar17 = *puVar14;
  *(undefined4 *)(lVar8 + 4) = 2;
  uVar7 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)uVar17 + 0xd80))
                    ((uint *)(ulong)uVar17);
  uVar2 = uRam0000000000e92aa8 /* '2 - Track %s' */;
  *(undefined4 *)(lVar8 + 0x68) = *(undefined4 *)((uVar7 & 0xffffffff) + 4);
  func_0x0027c1b8(uVar2,lVar8 + 0x28U & 0xffffffff);
  uVar2 = uRam0000000000e92aac /* 'Saving the online ghost data' */;
  *(undefined4 *)((ulong)*(uint *)((ulong)uVar1 + 0x10) + 0x1c) = 2;
  func_0x0027c1b8(uVar2);
  puVar9 = (undefined4 *)func_0x0071b0b8(0x18);
  func_0x0020a710((ulong)puVar9 & 0xffffffff);
  uVar17 = *puVar14;
  puVar9[1] = uVar1;
  *puVar9 = 2;
  puVar9[2] = (int)lVar8;
  uVar7 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)uVar17 + 0xd80))
                    ((uint *)(ulong)uVar17);
  uVar13 = func_0x001e5220((long)*(int *)(uVar7 & 0xffffffff));
  *(undefined1 *)(puVar9 + 3) = uVar13;
  iVar10 = *(int *)((ulong)param_1 + 0xbf58);
  puVar9[5] = uRam0000000000e92700;
  puVar9[4] = param_1;
  func_0x0021b5a8(iVar10 + 0x338,(ulong)puVar9 & 0xffffffff);
  if (0xf < uStack_78) {
    func_0x0071b0c8(uStack_8c);
  }
  uStack_8c = uStack_8c & 0xffffff;
  uStack_78 = 0xf;
  uStack_7c = 0;
  if (0xf < uStack_cc) {
    func_0x0071b0c8(uStack_e0);
  }
  if (0xf < uStack_b0) {
    uStack_e0 = uStack_e0 & 0xffffff;
    uStack_cc = 0xf;
    uStack_d0 = 0;
    func_0x0071b0c8(auStack_c4[0]);
  }
  return;
}



// ===== function 0x857788 =====

void FUN_00857788(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_14;
  
  func_0x0027c1b8(uRam0000000000e991b4 /* '%s: Retrieving ghost data' */,uRam0000000000e991b8 /* 'RetrieveGhost' */);
  cVar4 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_1 + 0x224))
                    ((ulong)param_1 & 0xffffffff);
  if (cVar4 == '\0') {
    return;
  }
  func_0x0027c1b8(uRam0000000000e990c4 /* '** Queuing mini statemachine %s ** **' */,uRam0000000000e98ff0);
  uStack_1c = param_1[3] + 1;
  uVar1 = param_1[5];
  param_1[3] = uStack_1c;
  uStack_18 = 1;
  uStack_14 = 0;
  uStack_20 = 0x40;
  if (uVar1 == 0) {
    uVar2 = param_1[6];
  }
  else {
    uVar2 = param_1[6];
    if ((uint)((int)(uVar2 - uVar1) >> 4) < (uint)((int)(param_1[7] - uVar1) >> 4)) {
      if (uVar2 != 0) {
        puVar3 = (undefined4 *)(ulong)uVar2;
        *puVar3 = 0x40;
        puVar3[1] = uStack_1c;
        *(undefined1 *)(puVar3 + 2) = 1;
        puVar3[3] = 0;
      }
      param_1[6] = uVar2 + 0x10;
      return;
    }
  }
  func_0x00850088((ulong)(param_1 + 4) & 0xffffffff,uVar2,1,&uStack_20);
  return;
}



// ===== function 0x7370d8 =====

void FUN_007370d8(uint *param_1)

{
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_1 + 0x144))((ulong)param_1 & 0xffffffff);
  return;
}



// ===== function 0x7378c0 =====

undefined1 FUN_007378c0(uint *param_1,undefined1 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(ulong)uRam0000000000e8fcd0;
  if ((uRam0000000000e8fcd0 & 1) != 0) {
    puVar2 = (uint *)(ulong)*(uint *)((long)puVar2 + ((ulong)*param_1 - 1) & 0xffffffff);
  }
  uVar1 = (*(code *)(ulong)*puVar2)((ulong)param_1 & 0xffffffff,param_2,param_3);
  return uVar1;
}



// ===== function 0x737168 =====

void FUN_00737168(uint *param_1)

{
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_1 + 0x154))((ulong)param_1 & 0xffffffff);
  return;
}



// ===== function 0x737120 =====

void FUN_00737120(uint *param_1)

{
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_1 + 0x148))((ulong)param_1 & 0xffffffff);
  return;
}



// ===== function 0x737090 =====

void FUN_00737090(uint *param_1)

{
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_1 + 0x140))((ulong)param_1 & 0xffffffff);
  return;
}



// ===== function 0x73e478 =====

undefined8 FUN_0073e478(uint *param_1)

{
  uint *puVar1;
  undefined8 in_LR;
  
  puVar1 = (uint *)(ulong)uRam0000000000e8ff3c;
  if ((uRam0000000000e8ff3c & 1) != 0) {
    puVar1 = (uint *)(ulong)*(uint *)((long)puVar1 + ((ulong)*param_1 - 1) & 0xffffffff);
  }
  (*(code *)(ulong)*puVar1)((ulong)param_1 & 0xffffffff);
  return in_LR;
}



// ===== function 0x740c80 =====

undefined8 FUN_00740c80(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined8 in_LR;
  
  puVar1 = (uint *)(ulong)uRam0000000000e90010;
  if ((uRam0000000000e90010 & 1) != 0) {
    puVar1 = (uint *)(ulong)*(uint *)((long)puVar1 + ((ulong)*param_1 - 1) & 0xffffffff);
  }
  (*(code *)(ulong)*puVar1)((ulong)param_1 & 0xffffffff,param_2);
  return in_LR;
}



// ===== function 0x188b0 =====
// decompile failed: Exception while decompiling 000188b0: process: timeout


// ===== function 0x14bc8 =====

void FUN_00014bc8(ulong param_1)

{
  uint *puVar1;
  
  func_0x0027c1b8(uRam0000000000e90344 /* 'DownloadGhostFromLeaderBoard' */);
  puVar1 = (uint *)(ulong)*(uint *)((param_1 & 0xffffffff) + 0xbf40);
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar1 + 0x23c))(puVar1);
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



// ===== function 0x29ce28 =====

void FUN_0029ce28(void)

{
  int iVar1;
  
  func_0x0027c1b8(uRam0000000000e9a260 /* 'PostGhostData' */);
  iVar1 = *(int *)(ulong)uRam0000000000e9a21c;
  if (iVar1 != 0) {
    func_0x002c1880(iVar1,0);
    func_0x002c1ac0(iVar1,uRam0000000000e9a264 /* 'Ghost data posted' */);
  }
  return;
}



// ===== function 0x29d040 =====

undefined8 FUN_0029d040(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  undefined8 in_LR;
  
  uVar4 = uRam0000000000e9a28c /* 'SetScore' */;
  func_0x0027c1b8(uRam0000000000e9a288 /* '%s: Setting Time Attack score' */,uRam0000000000e9a28c /* 'SetScore' */);
  uVar5 = uRam0000000000e9a290 /* 'BoardId: %d' */;
  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0x34);
  iVar6 = param_2[0xd] * 100 + param_2[0xc] + 99;
  *(int *)(param_1 + 0xd0) = iVar6;
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  uVar3 = param_2[3];
  *(undefined4 *)(param_1 + 0xa8) = *param_2;
  *(undefined4 *)(param_1 + 0xac) = uVar1;
  *(undefined4 *)(param_1 + 0xb0) = uVar2;
  *(undefined4 *)(param_1 + 0xb4) = uVar3;
  uVar1 = param_2[5];
  uVar2 = param_2[6];
  uVar3 = param_2[7];
  *(undefined4 *)(param_1 + 0xb8) = param_2[4];
  *(undefined4 *)(param_1 + 0xbc) = uVar1;
  *(undefined4 *)(param_1 + 0xc0) = uVar2;
  *(undefined4 *)(param_1 + 0xc4) = uVar3;
  *(undefined4 *)(param_1 + 200) = param_2[8];
  uVar1 = param_2[10];
  uVar2 = param_2[0xb];
  *(ulong *)(param_1 + 0xd8) = (ulong)(uint)param_2[9];
  *(undefined4 *)(param_1 + 0xec) = uVar1;
  *(undefined4 *)(param_1 + 0xe4) = uVar2;
  func_0x0027c1b8(uVar5,iVar6);
  func_0x0027c1b8(uRam0000000000e9a1f0 /* '%s: Best Score: %d, New Score: %d' */,uRam0000000000e9a1f4 /* 'IsNewScoreBetter' */,*(undefined8 *)(param_1 + 0x70),
                  param_2[9]);
  if ((*(long *)(param_1 + 0x70) <= (long)(ulong)(uint)param_2[9]) &&
     (*(long *)(param_1 + 0x70) != 0)) {
    func_0x0027c1b8(uRam0000000000e9a298 /* '%s: Score is not better, so not posting to Ranking Scoreboards.' */,uVar4);
    return in_LR;
  }
  puVar8 = (uint *)(ulong)uRam0000000000e9a204;
  puVar7 = (uint *)(ulong)*puVar8;
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar7 + 0x114))(puVar7);
  func_0x0027c1b8(uRam0000000000e9a20c /* 'CallPostNpScoreCB' */);
  puVar7 = (uint *)(ulong)*puVar8;
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar7 + 0x118))(puVar7);
  func_0x0027c1b8(uRam0000000000e9a208 /* 'CallPostNpGhostCB' */);
  func_0x0027c1b8(uRam0000000000e9a294 /* '%s: Score is better, posted to Ranking Scoreboards.' */,uVar4);
  return in_LR;
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
  FUN_002c9900(uVar7);
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



