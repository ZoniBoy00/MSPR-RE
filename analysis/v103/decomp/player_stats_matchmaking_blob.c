// ===== function 0x2abe58 =====

undefined8 FUN_002abe58(ushort *param_1,undefined8 param_2)

{
  ushort uVar1;
  ulong uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  undefined8 in_LR;
  
  uVar2 = (ulong)param_1 & 0xffffffff;
  func_0x0071b098(uVar2,param_2,0xb4);
  func_0x0027c1b8(uRam0000000000e9a5ec /* 'server version is %03d / current version is %03d' */,*param_1,8);
  uVar5 = (uint)*param_1;
  if ((uVar5 - 1 & 0xffff) < 8) {
    *(undefined1 *)(param_1 + 1) = 0;
    uVar3 = uRam0000000000e9a5d0 /* 'Upgraded PlayerStats to version %d' */;
    if (uVar5 < 8) {
      uVar5 = uVar5 * 4 + -4 + iRam0000000000e9a5cc;
      do {
        puVar4 = (uint *)(ulong)uVar5;
        uVar5 = uVar5 + 4;
        (*(code *)(ulong)*(uint *)(ulong)*puVar4)(uVar2);
        uVar1 = *param_1;
        *(undefined1 *)(param_1 + 1) = 1;
        *param_1 = uVar1 + 1;
        func_0x0027c1b8(uVar3,uVar1 + 1);
      } while (*param_1 < 8);
    }
    if (*(char *)((long)param_1 + 0x2b) != '\0') {
      func_0x0027c1b8(uRam0000000000e9a5e8 /* 'Incrementing PlayerStats dropout count on reconnection' */);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      func_0x002abaa8(uVar2);
      *(undefined1 *)((long)param_1 + 0x2b) = 0;
      *(undefined1 *)(param_1 + 1) = 1;
    }
    puVar6 = (uint *)(ulong)uRam0000000000e9a5b8;
    puVar4 = (uint *)(ulong)*puVar6;
    (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar4 + 0x104))(puVar4);
    puVar4 = (uint *)(ulong)*puVar6;
    (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar4 + 0x9b4))(puVar4);
    return in_LR;
  }
  func_0x0027c1b8(uRam0000000000e9a5f0 /* 'PlayerStats version is invalid. Assuming new account and resetting.' */);
  func_0x0071b038(uVar2,0,0xb4);
  param_1[4] = 0;
  param_1[5] = 1;
  param_1[2] = 0;
  param_1[3] = 1;
  *param_1 = 8;
  param_1[0x44] = 0;
  param_1[0x45] = 0xc84;
  param_1[0x42] = 0;
  param_1[0x43] = 0xc84;
  func_0x0071b038((ulong)(param_1 + 0x26) & 0xffffffff,0x20,0x10);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  *(undefined1 *)(param_1 + 1) = 1;
  return in_LR;
}



// ===== function 0x27ca10 =====

void FUN_0027ca10(long param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined1 *puVar5;
  char cVar9;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  ulong uVar10;
  uint *puVar11;
  undefined1 auStack_160 [21];
  undefined1 auStack_14b [17];
  undefined1 auStack_13a [266];
  
  puVar11 = (uint *)(ulong)uRam0000000000e997e0;
  uVar10 = (ulong)*puVar11;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(uVar10 + 0xc);
  func_0x002c1880(uVar10,0);
  uVar4 = *puVar11;
  if ((*(uint *)(ulong)uRam0000000000e99894 != 0) &&
     (*(int *)((ulong)*(uint *)(ulong)uRam0000000000e99894 + 0x68) != 0)) {
    uVar6 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(ulong)
                                                  uRam0000000000e997d4 + 0x9b4))
                      ((uint *)(ulong)*(uint *)(ulong)uRam0000000000e997d4);
    func_0x002c1ac0(uVar4,uRam0000000000e99898 /* "%s's PlayerStats haven't been uploaded because the server connection has been lost" */,uVar6);
    return;
  }
  puVar11 = (uint *)(ulong)uRam0000000000e997d4;
  cVar9 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar11 + 0x668))
                    ((uint *)(ulong)*puVar11);
  if (cVar9 == '\0') {
    uVar6 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar11 + 0x9b4))
                      ((uint *)(ulong)*puVar11);
    func_0x002c1ac0(uVar4,uRam0000000000e998a4 /* "%s's PlayerStats haven't been uploaded because they haven't changed" */,uVar6);
  }
  else {
    func_0x0071b038((ulong)auStack_160 & 0xffffffff,0,0x126);
    puVar5 = (undefined1 *)((ulong)auStack_14b & 0xffffffff);
    uVar1 = *(undefined1 *)(param_1 + 0x79);
    uVar2 = *(undefined1 *)(param_1 + 0x7a);
    uVar3 = *(undefined1 *)(param_1 + 0x7b);
    *puVar5 = *(undefined1 *)(param_1 + 0x78);
    puVar5[1] = uVar1;
    puVar5[2] = uVar2;
    puVar5[3] = uVar3;
    uVar1 = *(undefined1 *)(param_1 + 0x7d);
    uVar2 = *(undefined1 *)(param_1 + 0x7e);
    uVar3 = *(undefined1 *)(param_1 + 0x7f);
    puVar5[4] = *(undefined1 *)(param_1 + 0x7c);
    puVar5[5] = uVar1;
    puVar5[6] = uVar2;
    puVar5[7] = uVar3;
    uVar1 = *(undefined1 *)(param_1 + 0x81);
    uVar2 = *(undefined1 *)(param_1 + 0x82);
    uVar3 = *(undefined1 *)(param_1 + 0x83);
    puVar5[8] = *(undefined1 *)(param_1 + 0x80);
    puVar5[0xb] = uVar3;
    puVar5[9] = uVar1;
    puVar5[10] = uVar2;
    uVar1 = *(undefined1 *)(param_1 + 0x85);
    uVar2 = *(undefined1 *)(param_1 + 0x86);
    uVar3 = *(undefined1 *)(param_1 + 0x87);
    puVar5[0xc] = *(undefined1 *)(param_1 + 0x84);
    puVar5[0xd] = uVar1;
    puVar5[0xe] = uVar2;
    puVar5[0xf] = uVar3;
    puVar5[0x10] = *(undefined1 *)(param_1 + 0x88);
    uVar6 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar11 + 0x670))
                      ((uint *)(ulong)*puVar11);
    uVar7 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar11 + 0x9b4))
                      ((uint *)(ulong)*puVar11);
    func_0x0027c1b8(uVar6,uVar7);
    func_0x0071b098(auStack_13a,uVar6,0xb4);
    uVar6 = uRam0000000000e9989c;
    *(undefined4 *)(param_1 + 0x1c) = 10000;
    iVar8 = func_0x0071d4c8((ulong)auStack_160 & 0xffffffff,uVar6,param_1 + 8U & 0xffffffff);
    *(int *)(param_1 + 0x334) = iVar8;
    if (iVar8 != 0) {
      func_0x002c1d28(uVar4,0x26,uRam0000000000e998a0 /* 'MediusAccountUpdateStats() failed' */);
      return;
    }
  }
  return;
}



// ===== function 0x27ff88 =====

void FUN_0027ff88(undefined8 param_1,int param_2,undefined4 param_3,long param_4)

{
  int *piVar1;
  
  piVar1 = (int *)(ulong)*(uint *)(ulong)uRam0000000000e997e0;
  if (((*(uint *)(ulong)uRam0000000000e997e0 != 0) && (piVar1[3] == *(int *)(param_4 + 0x24))) &&
     ((piVar1[1] != 3 || (*piVar1 != 0x5b)))) {
    if (*(int *)(param_4 + 0x1c) != 0) {
      func_0x002c1c88(piVar1,9,param_3,uRam0000000000e999fc /* 'MediusGetPlayerInfo' */);
      return;
    }
    (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(ulong)
                                                  uRam0000000000e997d4 + 0x674))
              ((uint *)(ulong)*(uint *)(ulong)uRam0000000000e997d4,param_2 + 0x48);
    func_0x002c1ac0(piVar1,uRam0000000000e99a04 /* 'Retrieved PlayerStats' */);
    return;
  }
  func_0x0027c1b8(uRam0000000000e9982c /* 'StateMachine #%d redundant or aborted (Medius)' */,(long)*(int *)(param_4 + 0x24));
  return;
}



// ===== function 0x27edd8 =====

int FUN_0027edd8(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char cVar4;
  char *pcVar5;
  ulong uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  undefined1 *puVar12;
  uint *puVar13;
  undefined1 uStack_80;
  undefined1 uStack_7f;
  undefined1 uStack_7e;
  undefined1 uStack_7d;
  undefined1 uStack_7c;
  undefined1 uStack_7b;
  undefined1 uStack_7a;
  undefined1 uStack_79;
  undefined1 uStack_78;
  undefined1 uStack_77;
  undefined1 uStack_76;
  undefined1 uStack_75;
  undefined1 uStack_74;
  undefined1 uStack_73;
  undefined1 uStack_72;
  undefined1 uStack_71;
  undefined1 auStack_70 [40];
  
  func_0x0027c1b8(uRam0000000000e999a4 /* 'Starting cMedius...' */);
  func_0x0027c1b8(uRam0000000000e999a8 /* 'GameStats is %d bytes' */,0x38);
  func_0x0027c1b8(uRam0000000000e999ac /* 'PlayerStats is %d bytes' */,0xb4);
  puVar12 = (undefined1 *)(ulong)uRam0000000000e999b0 /* 'MOTORSTORM2' */;
  uVar1 = puVar12[1];
  uVar2 = puVar12[2];
  uVar3 = puVar12[3];
  *(undefined1 *)(param_1 + 0xc) = *puVar12;
  *(undefined1 *)((long)param_1 + 0x31) = uVar1;
  *(undefined1 *)((long)param_1 + 0x32) = uVar2;
  *(undefined1 *)((long)param_1 + 0x33) = uVar3;
  uVar1 = puVar12[5];
  uVar2 = puVar12[6];
  uVar3 = puVar12[7];
  *(undefined1 *)(param_1 + 0xd) = puVar12[4];
  *(undefined1 *)((long)param_1 + 0x35) = uVar1;
  *(undefined1 *)((long)param_1 + 0x36) = uVar2;
  *(undefined1 *)((long)param_1 + 0x37) = uVar3;
  uVar1 = puVar12[8];
  uVar2 = puVar12[9];
  uVar3 = puVar12[10];
  *(undefined1 *)((long)param_1 + 0x3b) = puVar12[0xb];
  *(undefined1 *)(param_1 + 0xe) = uVar1;
  *(undefined1 *)((long)param_1 + 0x39) = uVar2;
  *(undefined1 *)((long)param_1 + 0x3a) = uVar3;
  uVar9 = uRam0000000000e99830 /* 'PSID = %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x' */;
  syscall(0);
  *(undefined1 *)(param_1 + 0x18d) = uStack_80;
  *(undefined1 *)((long)param_1 + 0x635) = uStack_7f;
  *(undefined1 *)((long)param_1 + 0x636) = uStack_7e;
  *(undefined1 *)((long)param_1 + 0x637) = uStack_7d;
  *(undefined1 *)(param_1 + 0x18e) = uStack_7c;
  *(undefined1 *)((long)param_1 + 0x639) = uStack_7b;
  *(undefined1 *)((long)param_1 + 0x63a) = uStack_7a;
  *(undefined1 *)((long)param_1 + 0x63b) = uStack_79;
  *(undefined1 *)(param_1 + 399) = uStack_78;
  *(undefined1 *)((long)param_1 + 0x63d) = uStack_77;
  *(undefined1 *)((long)param_1 + 0x63e) = uStack_76;
  *(undefined1 *)((long)param_1 + 0x63f) = uStack_75;
  *(undefined1 *)(param_1 + 400) = uStack_74;
  *(undefined1 *)((long)param_1 + 0x643) = uStack_71;
  *(undefined1 *)((long)param_1 + 0x641) = uStack_73;
  *(undefined1 *)((long)param_1 + 0x642) = uStack_72;
  func_0x0027c1b8(uVar9,uStack_80,uStack_7f,uStack_7e,uStack_7d,uStack_7c,uStack_7b,uStack_7a,
                  uStack_79,uStack_78,uStack_77,uStack_76,uStack_75,uStack_74,uStack_73,uStack_72,
                  uStack_71);
  uVar11 = *(uint *)(ulong)uRam0000000000e997d8;
  if (uVar11 == 1) {
    uVar9 = 1;
LAB_0027f0a4:
    puVar7 = (undefined4 *)(ulong)uRam0000000000e997dc;
    param_1[0x1a3] = 0xffffffff;
    *puVar7 = uVar9;
    *(undefined1 *)((long)param_1 + 0x342) = 0;
    param_1[0x176] = 0xffffffff;
    param_1[0x205] = 0xffffffff;
    if (param_1[0x20a] != 0) {
      func_0x00bdf520(param_1[0x20a]);
    }
LAB_0027f0e0:
    if (param_1[0x20b] != 0) {
      func_0x00bdf520(param_1[0x20b]);
    }
  }
  else {
    if ((int)uVar11 < 2) {
      uVar9 = (undefined4)
              ((((((long)((int)uVar11 >> 0x1f) ^ (ulong)uVar11) - (long)((int)uVar11 >> 0x1f)) - 1 &
                0xffffffff) >> 0x1f) << 1);
      goto LAB_0027f0a4;
    }
    if (uVar11 == 2) {
      uVar9 = 3;
      goto LAB_0027f0a4;
    }
    if (uVar11 == 3) {
      uVar9 = 4;
      goto LAB_0027f0a4;
    }
    puVar7 = (undefined4 *)(ulong)uRam0000000000e997dc;
    param_1[0x1a3] = 0xffffffff;
    *puVar7 = 0;
    *(undefined1 *)((long)param_1 + 0x342) = 0;
    param_1[0x176] = 0xffffffff;
    param_1[0x205] = 0xffffffff;
    if (param_1[0x20a] == 0) goto LAB_0027f0e0;
    func_0x00bdf520(param_1[0x20a]);
    if (param_1[0x20b] != 0) {
      func_0x00bdf520(param_1[0x20b]);
      puVar13 = (uint *)(ulong)uRam0000000000e997d4;
      *(undefined1 *)(param_1 + 0x1e) = 0;
      param_1[0x172] = 0;
      *(undefined1 *)(param_1 + 0x321) = 0;
      *(undefined1 *)((long)param_1 + 0xc85) = 0;
      *(undefined1 *)((long)param_1 + 0xc86) = 0;
      param_1[800] = 0;
      param_1[0x192] = 0;
      param_1[0x202] = 0;
      param_1[0x323] = 0;
      param_1[0x212] = 0;
      *(undefined1 *)(param_1 + 0x214) = 0;
      param_1[0x213] = 0;
      *(undefined1 *)((long)param_1 + 0x851) = 0;
      *(undefined1 *)((long)param_1 + 0x845) = 0;
      param_1[0x216] = 0;
      *(undefined1 *)(param_1 + 0x211) = 0;
      *(undefined1 *)(param_1 + 0x191) = 0;
      param_1[0x201] = 0xffffffff;
      *(undefined1 *)(param_1 + 0x322) = 0;
      param_1[0x210] = 0;
      param_1[0x20d] = 0;
      param_1[0x20e] = 0;
      param_1[0x20f] = 0;
      uVar11 = *puVar13;
      param_1[4] = 0xffffffff;
      param_1[0x7c] = 0;
      *param_1 = 0xffffffff;
      param_1[0xce] = 0;
      goto LAB_0027f178;
    }
  }
  puVar13 = (uint *)(ulong)uRam0000000000e997d4;
  *(undefined1 *)(param_1 + 0x1e) = 0;
  param_1[0x172] = 0;
  *(undefined1 *)(param_1 + 0x321) = 0;
  *(undefined1 *)((long)param_1 + 0xc85) = 0;
  *(undefined1 *)((long)param_1 + 0xc86) = 0;
  param_1[800] = 0;
  param_1[0x192] = 0;
  param_1[0x202] = 0;
  param_1[0x323] = 0;
  param_1[0x212] = 0;
  *(undefined1 *)(param_1 + 0x214) = 0;
  param_1[0x213] = 0;
  *(undefined1 *)((long)param_1 + 0x851) = 0;
  *(undefined1 *)((long)param_1 + 0x845) = 0;
  param_1[0x216] = 0;
  *(undefined1 *)(param_1 + 0x211) = 0;
  *(undefined1 *)(param_1 + 0x191) = 0;
  param_1[0x201] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x322) = 0;
  param_1[0x210] = 0;
  param_1[0x20d] = 0;
  param_1[0x20e] = 0;
  param_1[0x20f] = 0;
  uVar11 = *puVar13;
  param_1[4] = 0xffffffff;
  param_1[0x7c] = 0;
  *param_1 = 0xffffffff;
  param_1[0xce] = 0;
LAB_0027f178:
  uVar8 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)uVar11 + 0xc14))();
  uVar9 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar13 + 0xc20))
                    ((uint *)(ulong)*puVar13);
  param_1[0x7b] = uVar9;
  uVar11 = uVar8;
  do {
    pcVar5 = (char *)(ulong)uVar11;
    uVar11 = uVar11 + 1;
    cVar4 = *pcVar5;
    if (cVar4 == 0) {
      func_0x0071b048((long)param_1 + 0x1d9U & 0xffffffff,uVar8);
      *(char *)((long)param_1 + 0x159) = cVar4;
      goto LAB_0027f21c;
    }
    iVar10 = func_0x0071ce18(uRam0000000000e9984c,(long)(int)cVar4);
  } while (iVar10 != 0);
  func_0x0071b048((long)param_1 + 0x159U & 0xffffffff,uVar8);
  *(undefined1 *)((long)param_1 + 0x1d9) = 0;
LAB_0027f21c:
  iVar10 = func_0x0071d618(1);
  if (iVar10 != 0) {
    func_0x0027c1b8(uRam0000000000e999b4 /* 'MediusInitialize() failed. MediusError = 0x%08x' */,(long)(int)param_1[0xcd]);
    return 0;
  }
  uVar6 = (long)param_1 + 0x89U & 0xffffffff;
  func_0x0071d628(uVar6);
  func_0x0027c1b8(uRam0000000000e999b8 /* 'Medius Client Library %s' */,uVar6);
  uVar6 = (ulong)auStack_70 & 0xffffffff;
  *(undefined1 (*) [16])((ulong)auStack_70 & 0xfffffff0) = (undefined1  [16])0x0;
  *(undefined4 *)(uVar6 + 0x18) = 0;
  *(undefined8 *)(uVar6 + 0x10) = 0;
  func_0x0071d638(uVar6);
  uVar11 = func_0x0071d648(uVar6,(ulong)param_1 & 0xffffffff);
  param_1[0xcd] = uVar11;
  if (uVar11 == 0) {
    iVar10 = 1;
  }
  else {
    *param_1 = 0xffffffff;
    iVar10 = -((int)((((int)uVar11 >> 0x1f ^ uVar11) - ((int)uVar11 >> 0x1f)) + -1) >> 0x1f);
    if (iVar10 == 0) {
      return 0;
    }
  }
  func_0x0027baa8((ulong)param_1 & 0xffffffff);
  func_0x0027c1b8(uRam0000000000e999bc /* 'Started cMedius' */);
  return iVar10;
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
  
  func_0x0027c1b8(uRam0000000000e998e8 /* '\n\n\t\t------------Start Match Party Request----------------' */);
  puVar15 = (uint *)(ulong)uRam0000000000e997d4;
  iVar7 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*puVar15 + 0xc2c))
                    ((uint *)(ulong)*puVar15);
  func_0x0027c1b8(uRam0000000000e998ec /* 'MY LOCATION IS %d' */,(long)iVar7);
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
  func_0x002c1d28(uVar2,0x2e,uRam0000000000e99824 /* 'Error Finding Match Make, SuperSetNot avaliable' */);
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
      func_0x002c1d28(uVar2,0x2e,uRam0000000000e998f0 /* 'Error Finding Match Make, user does not have account ID**\n' */);
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
    func_0x0027c1b8(uRam0000000000e998f4 /* 'Player %d: Account ID for Party = %d   Rank Level = %d' */,uVar18,uVar10,(long)iVar9);
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
    func_0x0027c1b8(uRam0000000000e998f8 /* 'RETRIED MATCH MAKING, Last Attempt, Using Zero DLC' */);
  }
  func_0x0027c1b8(uRam0000000000e998fc);
  func_0x0027c1b8(uRam0000000000e99900 /* '\n\n\tData Blob being sent to the server' */);
  uStack_100._0_1_ = (undefined1)((ulong)uVar4 >> 0x38);
  func_0x0027c1b8(uRam0000000000e99904 /* '* Ranked Game \t\t= %d' */,uStack_100._0_1_);
  uStack_100._4_4_ = (int)uVar4;
  func_0x0027c1b8(uRam0000000000e99908 /* '* Rank Level  \t\t= %d' */,(long)uStack_100._4_4_);
  func_0x0027c1b8(uRam0000000000e9990c /* '* Location ID \t\t= %d' */,(long)iVar12);
  func_0x0027c1b8(uRam0000000000e99910);
  func_0x0027c1b8(uRam0000000000e99914 /* '* Party size\t\t= %d' */,(long)iVar8);
  func_0x0027c1b8(uRam0000000000e99918 /* '* Min Players\t\t= %d' */,uVar10);
  func_0x0027c1b8(uRam0000000000e9991c /* '* Super Set Info\t= %d' */,(long)iVar7);
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
    func_0x002c1d28(uVar2,0x2e,uRam0000000000e99928 /* 'Error In call to Finding Matching Game From MMS %d' */,(long)iVar7);
  }
  *(undefined4 *)(param_1 + 0x1c) = 20000;
  return;
}



