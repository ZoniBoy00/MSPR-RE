// ===== function 0x2aadf8 =====

void FUN_002aadf8(uint *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = func_0x00768b58();
  cVar2 = func_0x002af920(uVar1,(long)param_2,(long)param_3);
  if (cVar2 != '\0') {
    uVar1 = func_0x002d4ec8();
    func_0x002d5068(uVar1,0);
    (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_1 + 0x1d8))
              ((ulong)param_1 & 0xffffffff,(long)param_2);
    func_0x00283f90(0xcb6);
    func_0x002d50a0((double)fRam0000000000e9a5b0,0);
  }
  return;
}



// ===== function 0x2aaed0 =====

void FUN_002aaed0(undefined8 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x00768b58();
  func_0x002af998(uVar1,(long)param_2);
  return;
}



// ===== function 0x2aaf10 =====

void FUN_002aaf10(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x00768b58();
  func_0x002acb68(uVar1,*(undefined4 *)(param_1 + 0x1720));
  return;
}



// ===== function 0x2aaf50 =====

void FUN_002aaf50(long param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined4 uVar5;
  uint *puVar6;
  ulong uVar7;
  ulong uVar8;
  undefined4 auStack_50 [6];
  
  uVar4 = func_0x0071b0b8(0x10);
  uVar8 = uVar4 & 0xffffffff;
  uVar3 = *(uint *)(param_1 + 0x1550);
  *(undefined4 *)(uVar4 + 4) = 0;
  iVar2 = *(int *)(uVar8 + 4);
  auStack_50[0] = *(undefined4 *)((ulong)uVar3 + 4);
  *(int *)(param_1 + 0x1720) = (int)uVar4;
  *(undefined4 *)(uVar4 + 0xc) = 0;
  *(undefined4 *)(uVar4 + 8) = 0;
  if ((iVar2 == 0) ||
     (uVar3 = *(uint *)(uVar8 + 8), (uint)(-iVar2 >> 2) <= (uint)((int)(uVar3 - iVar2) >> 2))) {
    func_0x00757120(uVar8,0,1,auStack_50);
  }
  else {
    *(uint *)(uVar4 + 8) = uVar3 + 4;
    *(undefined4 *)(ulong)uVar3 = auStack_50[0];
  }
  uVar3 = *(uint *)(param_1 + 0x1664);
  cVar1 = *(char *)((ulong)*(uint *)((ulong)*(uint *)(param_1 + 0x1554) + 0x14) + 2);
  uVar8 = (ulong)*(uint *)(ulong)uVar3;
  while (uVar3 != (uint)uVar8) {
    while( true ) {
      uVar4 = func_0x002bb8b8(param_1 + 0x1660U & 0xffffffff,(long)*(int *)(uVar8 + 0x10));
      if ((1 << ((int)cVar1 - 1U & 0x3f) & *(uint *)((uVar4 & 0xffffffff) + 0xc4)) != 0) {
        uVar4 = (ulong)*(uint *)(param_1 + 0x1720);
        iVar2 = *(int *)(uVar4 + 4);
        if ((iVar2 == 0) ||
           (uVar3 = *(uint *)(uVar4 + 8),
           (uint)(*(int *)(uVar4 + 0xc) - iVar2 >> 2) <= (uint)((int)(uVar3 - iVar2) >> 2))) {
          func_0x00757120(uVar4,*(undefined4 *)(uVar4 + 8),1,uVar8 + 0xc & 0xffffffff);
        }
        else {
          *(uint *)(uVar4 + 8) = uVar3 + 4;
          *(undefined4 *)(ulong)uVar3 = *(undefined4 *)(uVar8 + 0xc & 0xffffffff);
        }
      }
      if (*(char *)(uVar8 + 0x15) != '\0') goto LAB_002ab1c8;
      uVar3 = *(uint *)(uVar8 + 8);
      puVar6 = (uint *)(ulong)uVar3;
      if (*(char *)((long)puVar6 + 0x15) == '\0') break;
      uVar7 = (ulong)*(uint *)(uVar8 + 4);
      uVar4 = (ulong)*(uint *)(uVar8 + 4);
      if ((*(char *)(uVar4 + 0x15) == '\0') && (*(int *)(uVar4 + 8) == (int)uVar8)) {
        do {
          iVar2 = (int)uVar7;
          uVar7 = (ulong)*(uint *)(uVar4 + 4);
          uVar4 = (ulong)*(uint *)(uVar4 + 4);
          if (*(char *)(uVar4 + 0x15) != '\0') break;
        } while (*(int *)(uVar4 + 8) == iVar2);
      }
      uVar8 = uVar7;
      if (*(int *)(param_1 + 0x1664) == (int)uVar7) goto LAB_002ab12c;
    }
    do {
      uVar8 = (ulong)uVar3;
      uVar3 = *puVar6;
      puVar6 = (uint *)(ulong)uVar3;
    } while (*(char *)((long)puVar6 + 0x15) == '\0');
LAB_002ab1c8:
    uVar3 = *(uint *)(param_1 + 0x1664);
  }
LAB_002ab12c:
  *(undefined1 *)(param_1 + 0x169f) = 0;
  *(undefined1 *)(param_1 + 0x1698) = 0;
  *(undefined1 *)(param_1 + 0x1699) = 0;
  *(undefined1 *)(param_1 + 0x169a) = 0;
  *(undefined1 *)(param_1 + 0x169b) = 0;
  *(undefined1 *)(param_1 + 0x169c) = 0;
  *(undefined1 *)(param_1 + 0x169d) = 0;
  *(undefined1 *)(param_1 + 0x169e) = 0;
  uVar5 = func_0x002d4ec8();
  func_0x002d4ff0(uVar5);
  uVar5 = func_0x00768b58();
  func_0x002adaa8(uVar5,*(undefined4 *)(param_1 + 0x1720));
  return;
}



// ===== function 0x2ab200 =====

void FUN_002ab200(undefined8 param_1,byte param_2,long param_3)

{
  uint *puVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_50 [4];
  uint uStack_4c;
  uint uStack_48;
  undefined4 uStack_44;
  
  uStack_44 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  if (*(uint *)(param_3 + 0x18) < 0x10) {
    uVar3 = param_3 + 4;
  }
  else {
    uVar3 = (ulong)*(uint *)(param_3 + 4);
  }
  func_0x0071b518(uVar3 & 0xffffffff,auStack_50,uRam0000000000e9a578);
  uVar4 = func_0x0071b198();
  iVar5 = func_0x0071b258();
  if (*(uint *)((ulong)uStack_4c + 0x18) < 0x10) {
    iVar6 = func_0x0071b1a8(uVar4,uStack_4c + 4);
  }
  else {
    iVar6 = func_0x0071b1a8(uVar4,*(undefined4 *)((ulong)uStack_4c + 4));
  }
  if (iVar6 != 0) {
    func_0x0071b1b8(iVar6,(long)iVar5,uVar4,param_2);
  }
  if (*(uint *)((ulong)(uStack_4c + 0x1c) + 0x18) < 0x10) {
    iVar6 = uStack_4c + 0x20;
  }
  else {
    iVar6 = *(int *)((ulong)(uStack_4c + 0x1c) + 4);
  }
  iVar6 = func_0x0071b1a8(uVar4,iVar6);
  if (iVar6 != 0) {
    func_0x0071b1b8(iVar6,(long)iVar5,uVar4,param_2);
  }
  if (*(uint *)((ulong)(uStack_4c + 0x38) + 0x18) < 0x10) {
    iVar5 = uStack_4c + 0x3c;
  }
  else {
    iVar5 = *(int *)((ulong)(uStack_4c + 0x38) + 4);
  }
  iVar5 = func_0x0071b1a8(uVar4,iVar5);
  if (iVar5 != 0) {
    func_0x0071b268(iVar5,param_2 ^ 1);
  }
  uVar2 = uStack_48;
  if (uStack_4c != 0) {
    uVar10 = uStack_4c + 0x18;
    uVar7 = uStack_4c;
    if (uStack_4c == uStack_48) {
      func_0x0071b0c8(uStack_4c);
    }
    else {
      do {
        while (puVar1 = (uint *)(ulong)uVar10, 0xf < *puVar1) {
          uVar9 = uVar7 + 0x1c;
          func_0x0071b0c8(*(undefined4 *)((ulong)uVar7 + 4));
          uVar8 = uVar10 - 4;
          *puVar1 = 0xf;
          *(undefined1 *)((ulong)uVar7 + 4) = 0;
          uVar10 = uVar10 + 0x1c;
          *(undefined4 *)(ulong)uVar8 = 0;
          uVar7 = uVar9;
          if (uVar2 == uVar9) goto LAB_002ab3c0;
        }
        uVar8 = uVar7 + 0x1c;
        *puVar1 = 0xf;
        *(undefined1 *)((ulong)uVar7 + 4) = 0;
        *(undefined4 *)(ulong)(uVar10 - 4) = 0;
        uVar10 = uVar10 + 0x1c;
        uVar7 = uVar8;
      } while (uVar2 != uVar8);
LAB_002ab3c0:
      func_0x0071b0c8(uStack_4c);
    }
  }
  return;
}



// ===== function 0x2ab510 =====

void FUN_002ab510(long param_1)

{
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}



// ===== function 0x2ab530 =====

void FUN_002ab530(long param_1,undefined1 param_2)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_1 + 0x48);
  uVar1 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)*(uint *)(ulong)
                                                  uRam0000000000e9a5b8 + 0x408))
                    ((uint *)(ulong)*(uint *)(ulong)uRam0000000000e9a5b8);
  if (*(int *)((uVar1 & 0xffffffff) + 200) - 5U < 2) {
    uVar2 = *piVar4 + 1;
    iVar3 = uVar2 + (((int)uVar2 >> 4) + (uint)((int)uVar2 < 0 && (uVar2 & 0xf) != 0)) * -0x10;
    *piVar4 = iVar3;
    *(undefined1 *)(((ulong)piVar4 & 0xffffffff) + (long)iVar3 + 4) = param_2;
  }
  return;
}



// ===== function 0x2ab630 =====

/* WARNING: Removing unreachable block (ram,0x002ab5f4) */

undefined8 FUN_002ab630(void)

{
  undefined8 in_LR;
  
  func_0x003f05c8(uRam0000000000e9a5bc);
  return in_LR;
}



// ===== function 0x2ab640 =====

void FUN_002ab640(void)

{
  func_0x002b7210(uRam0000000000e9a5c4);
  return;
}



// ===== function 0x2ab668 =====

void FUN_002ab668(undefined2 *param_1)

{
  func_0x0071b038(param_1,0,0xb4);
  *param_1 = 5;
  return;
}



// ===== function 0x2ab6a8 =====

void FUN_002ab6a8(undefined2 *param_1)

{
  func_0x0071b038(param_1,0,0xb4);
  *param_1 = 4;
  return;
}



// ===== function 0x2ab6e8 =====

void FUN_002ab6e8(undefined2 *param_1)

{
  func_0x0071b038(param_1,0,0xb4);
  *param_1 = 3;
  return;
}



// ===== function 0x2ab728 =====

void FUN_002ab728(long param_1)

{
  undefined1 auStack_f0 [200];
  
  func_0x0071b098((ulong)auStack_f0 & 0xffffffff,(ulong)(param_1 + 0x48) & 0xffffffff,0x58);
  func_0x0071b038(param_1 + 0x4cU & 0xffffffff,0x20,0x10);
  *(undefined4 *)(param_1 + 0x48) = 0;
  func_0x0071b098(param_1 + 0x5cU & 0xffffffff,(ulong)auStack_f0 & 0xffffffff,0x58);
  return;
}



// ===== function 0x2ab7b8 =====

void FUN_002ab7b8(undefined2 *param_1)

{
  func_0x0071b038((ulong)param_1 & 0xffffffff,0,0xb4);
  func_0x0071b038((ulong)param_1 & 0xffffffff,0,0xb4);
  *(undefined4 *)(param_1 + 0x44) = 0xc84;
  *param_1 = 8;
  *(undefined4 *)(param_1 + 2) = 1;
  *(undefined4 *)(param_1 + 4) = 1;
  *(undefined4 *)(param_1 + 0x42) = 0xc84;
  func_0x0071b038((ulong)(param_1 + 0x26) & 0xffffffff,0x20,0x10);
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}



// ===== function 0x2ab868 =====

undefined4 FUN_002ab868(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar2 = uRam0000000000e9a5c4;
  pcVar3 = (char *)(ulong)uRam0000000000e9a5c0;
  if (*pcVar3 != '\0') {
    uVar2 = func_0x002b7880(uRam0000000000e9a5c4,(long)*(int *)(param_1 + 8));
    return uVar2;
  }
  FUN_002b94c0(uRam0000000000e9a5c4);
  uVar1 = uRam0000000000e9a5c8;
  *pcVar3 = '\x01';
  func_0x0071b348(uVar1);
  uVar2 = func_0x002b7880(uVar2,(long)*(int *)(param_1 + 8));
  return uVar2;
}



// ===== function 0x2ab928 =====

undefined4 FUN_002ab928(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar2 = uRam0000000000e9a5c4;
  pcVar3 = (char *)(ulong)uRam0000000000e9a5c0;
  if (*pcVar3 != '\0') {
    uVar2 = FUN_002b6f80(uRam0000000000e9a5c4,(long)*(int *)(param_1 + 8));
    return uVar2;
  }
  FUN_002b94c0(uRam0000000000e9a5c4);
  uVar1 = uRam0000000000e9a5c8;
  *pcVar3 = '\x01';
  func_0x0071b348(uVar1);
  uVar2 = FUN_002b6f80(uVar2,(long)*(int *)(param_1 + 8));
  return uVar2;
}



// ===== function 0x2ab9e8 =====

undefined1 FUN_002ab9e8(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  char *pcVar4;
  
  uVar1 = uRam0000000000e9a5c4;
  pcVar4 = (char *)(ulong)uRam0000000000e9a5c0;
  if (*pcVar4 != '\0') {
    uVar3 = func_0x002b73a8(uRam0000000000e9a5c4,(long)*(int *)(param_1 + 8));
    return uVar3;
  }
  FUN_002b94c0(uRam0000000000e9a5c4);
  uVar2 = uRam0000000000e9a5c8;
  *pcVar4 = '\x01';
  func_0x0071b348(uVar2);
  uVar3 = func_0x002b73a8(uVar1,(long)*(int *)(param_1 + 8));
  return uVar3;
}



// ===== function 0x2abaa8 =====

void FUN_002abaa8(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  char *pcVar7;
  ulong uVar8;
  int iVar9;
  
  if (*(char *)(param_1 + 0x28) == '\0') {
    return;
  }
  pcVar7 = (char *)(ulong)uRam0000000000e9a5c0;
  uVar4 = *(int *)(param_1 + 0xc) + 1;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(uint *)(param_1 + 0xc) = uVar4;
  *(undefined1 *)(param_1 + 0x2a) = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  if (*pcVar7 == '\0') {
    FUN_002b94c0(uRam0000000000e9a5c4);
    uVar2 = uRam0000000000e9a5c8;
    *pcVar7 = '\x01';
    func_0x0071b348(uVar2);
    uVar6 = (ulong)uRam0000000000e9a5c4;
    uVar4 = *(uint *)(param_1 + 0xc) ^ 0x80000000;
    uVar8 = (ulong)(int)(*(uint *)(uVar6 + 0x10) ^ 0x80000000);
    uVar3 = (ulong)(int)(uVar4 + 0x80000000 & ~-(uint)(uVar4 < 0x80000000) ^ 0x80000000);
    iVar9 = *(int *)(((ulong)*(uint *)(uVar6 + 0x10) + (uVar3 - uVar8 & -(ulong)(uVar3 < uVar8)) &
                     0x3fffffff) * 4 + (ulong)*(uint *)(uVar6 + 0x58) & 0xffffffff);
    func_0x0027c1b8(uRam0000000000e9a5dc /* 'PLAYER QUITTED THIS RANKED GAME. Adding penalty points = %d, Quits = %d' */,(long)iVar9,(long)(int)*(uint *)(param_1 + 0xc));
    func_0x0027c1b8(uRam0000000000e9a5e0 /* 'XP was = %d ' */,(long)*(int *)(param_1 + 8));
    uVar2 = uRam0000000000e9a5e4 /* 'XP changed to = %d ' */;
    iVar9 = iVar9 + *(int *)(param_1 + 8);
    *(int *)(param_1 + 8) = iVar9;
    func_0x0027c1b8(uVar2,(long)iVar9);
    iVar9 = *(int *)(param_1 + 8);
    if (*pcVar7 != '\0') goto LAB_002abd24;
  }
  else {
    uVar6 = (ulong)uRam0000000000e9a5c4;
    uVar8 = (ulong)(int)(*(uint *)(uVar6 + 0x10) ^ 0x80000000);
    uVar3 = (ulong)(int)((uVar4 ^ 0x80000000) + 0x80000000 &
                         ~-(uint)((uVar4 ^ 0x80000000) < 0x80000000) ^ 0x80000000);
    iVar9 = *(int *)(((ulong)*(uint *)(uVar6 + 0x10) + (uVar3 - uVar8 & -(ulong)(uVar3 < uVar8)) &
                     0x3fffffff) * 4 + (ulong)*(uint *)(uVar6 + 0x58) & 0xffffffff);
    func_0x0027c1b8(uRam0000000000e9a5dc /* 'PLAYER QUITTED THIS RANKED GAME. Adding penalty points = %d, Quits = %d' */,(long)iVar9,(long)(int)uVar4);
    func_0x0027c1b8(uRam0000000000e9a5e0 /* 'XP was = %d ' */,(long)*(int *)(param_1 + 8));
    uVar2 = uRam0000000000e9a5e4 /* 'XP changed to = %d ' */;
    iVar9 = iVar9 + *(int *)(param_1 + 8);
    *(int *)(param_1 + 8) = iVar9;
    func_0x0027c1b8(uVar2,(long)iVar9);
    iVar9 = *(int *)(param_1 + 8);
    if (*pcVar7 != '\0') {
      uVar3 = (ulong)(int)(*(uint *)(uVar6 + 4) ^ 0x80000000);
      iVar1 = *(int *)(((ulong)*(uint *)(uVar6 + 4) +
                        (-uVar3 - 0x80000000 & -(ulong)(0xffffffff80000000 < uVar3)) & 0xfffffff) *
                       0x10 + (ulong)*(uint *)(uVar6 + 0x38) & 0xffffffff);
      if (iVar1 <= iVar9) {
        return;
      }
      *(int *)(param_1 + 8) = iVar1;
      return;
    }
  }
  FUN_002b94c0(uRam0000000000e9a5c4);
  uVar2 = uRam0000000000e9a5c8;
  *pcVar7 = '\x01';
  func_0x0071b348(uVar2);
LAB_002abd24:
  uVar5 = (ulong)*(uint *)(uVar6 + 4);
  uVar3 = (ulong)(int)(*(uint *)(uVar6 + 4) ^ 0x80000000);
  uVar8 = (ulong)*(uint *)(uVar6 + 0x38);
  if (*(int *)((uVar5 + (-uVar3 - 0x80000000 & -(ulong)(0xffffffff80000000 < uVar3)) & 0xfffffff) *
               0x10 + uVar8 & 0xffffffff) <= iVar9) {
    return;
  }
  if (*pcVar7 == '\0') {
    FUN_002b94c0(uRam0000000000e9a5c4);
    uVar2 = uRam0000000000e9a5c8;
    *pcVar7 = '\x01';
    func_0x0071b348(uVar2);
    uVar8 = (ulong)*(uint *)(uVar6 + 0x38);
    uVar5 = (ulong)*(uint *)(uVar6 + 4);
  }
  uVar3 = (ulong)(int)((uint)uVar5 ^ 0x80000000);
  *(undefined4 *)(param_1 + 8) =
       *(undefined4 *)
        ((uVar5 + (-uVar3 - 0x80000000 & -(ulong)(0xffffffff80000000 < uVar3)) & 0xfffffff) * 0x10 +
         uVar8 & 0xffffffff);
  return;
}



