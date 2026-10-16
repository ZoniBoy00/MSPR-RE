// ===== function 0xa17fb0 =====

void FUN_00a17fb0(undefined4 *param_1,uint *param_2,int param_3)

{
  ulong uVar1;
  ulong uVar2;
  char cVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  
  *param_1 = uRam0000000000e94964;
  param_1[2] = 1;
  param_1[4] = 0;
  param_1[6] = 0xffffffff;
  param_1[7] = 0;
  param_1[5] = 0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  ((undefined4 *)((ulong)(param_1 + 0xe) & 0xffffffff))[1] = 0;
  ((undefined4 *)((ulong)(param_1 + 0x10) & 0xffffffff))[1] = 0;
  ((undefined4 *)((ulong)(param_1 + 0x12) & 0xffffffff))[1] = 0;
  ((undefined4 *)((ulong)(param_1 + 0x14) & 0xffffffff))[1] = 0;
  ((undefined4 *)((ulong)(param_1 + 0x16) & 0xffffffff))[1] = 0;
  ((undefined4 *)((ulong)(param_1 + 0x18) & 0xffffffff))[1] = 0;
  ((undefined4 *)((ulong)(param_1 + 0x1a) & 0xffffffff))[1] = 0;
  ((undefined4 *)((ulong)(param_1 + 0x1c) & 0xffffffff))[1] = 0;
  ((undefined4 *)((ulong)(param_1 + 0x1e) & 0xffffffff))[1] = 0;
  param_1[10] = 0;
  ((undefined4 *)((ulong)(param_1 + 0x20) & 0xffffffff))[1] = 0;
  param_1[0xc] = 0;
  ((undefined4 *)((ulong)(param_1 + 0x22) & 0xffffffff))[1] = 0;
  *(undefined4 *)((ulong)(param_1 + 0xe) & 0xffffffff) = 0;
  ((undefined4 *)((ulong)(param_1 + 0x24) & 0xffffffff))[1] = 0;
  *(undefined4 *)((ulong)(param_1 + 0x10) & 0xffffffff) = 0;
  ((undefined4 *)((ulong)(param_1 + 0x26) & 0xffffffff))[1] = 0;
  *(undefined4 *)((ulong)(param_1 + 0x12) & 0xffffffff) = 0;
  ((undefined4 *)((ulong)(param_1 + 0x28) & 0xffffffff))[1] = 0;
  *(undefined4 *)((ulong)(param_1 + 0x14) & 0xffffffff) = 0;
  ((undefined4 *)((ulong)(param_1 + 0x2a) & 0xffffffff))[1] = 0;
  *(undefined4 *)((ulong)(param_1 + 0x16) & 0xffffffff) = 0;
  *(undefined4 *)((ulong)(param_1 + 0x18) & 0xffffffff) = 0;
  *(undefined4 *)((ulong)(param_1 + 0x1a) & 0xffffffff) = 0;
  *(undefined4 *)((ulong)(param_1 + 0x1c) & 0xffffffff) = 0;
  *(undefined4 *)((ulong)(param_1 + 0x1e) & 0xffffffff) = 0;
  *(undefined4 *)((ulong)(param_1 + 0x20) & 0xffffffff) = 0;
  *(undefined4 *)((ulong)(param_1 + 0x22) & 0xffffffff) = 0;
  *(undefined4 *)((ulong)(param_1 + 0x24) & 0xffffffff) = 0;
  *(undefined4 *)((ulong)(param_1 + 0x26) & 0xffffffff) = 0;
  *(undefined4 *)((ulong)(param_1 + 0x28) & 0xffffffff) = 0;
  *(undefined4 *)((ulong)(param_1 + 0x2a) & 0xffffffff) = 0;
  cVar3 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_2 + 0x44))
                    ((ulong)param_2 & 0xffffffff);
  iVar8 = 0;
  if ((cVar3 == '\0') && (iVar8 = param_3, 0xfffffff < param_3)) {
    iVar8 = 0xfffffff;
  }
  uVar1 = (ulong)param_1 & 0xffffffff;
  lVar9 = 0x200;
  lVar6 = 1;
  param_1[0x2d] = 0;
  param_1[1] = (int)param_2;
  param_1[9] = iVar8;
  *(undefined1 *)(uVar1 + 0xf4) = 1;
  do {
    iVar7 = (int)lVar6;
    iVar8 = 1;
    if (((((8 < iVar7) && (iVar8 = 2, 0x10 < iVar7)) && (iVar8 = 3, 0x20 < iVar7)) &&
        (((iVar8 = 4, 0x30 < iVar7 && (iVar8 = 5, 0x40 < iVar7)) &&
         ((iVar8 = 6, 0x60 < iVar7 && ((iVar8 = 7, 0x80 < iVar7 && (iVar8 = 8, 0xa0 < iVar7))))))))
       && ((iVar8 = 9, 0xc0 < iVar7 && ((iVar8 = 10, 0x100 < iVar7 && (iVar8 = 0xc, iVar7 < 0x141)))
           ))) {
      iVar8 = 0xb;
    }
    *(char *)((lVar6 + (long)param_1 & 0xffffffffU) + 0xf4) = (char)iVar8;
    *(int *)(uVar1 + (long)(iVar8 * 4 + 0xb0)) = iVar7;
    lVar6 = lVar6 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  uVar5 = 1;
  lVar6 = 0x400;
  uVar4 = 0;
  do {
    iVar7 = (int)lVar6;
    iVar8 = 2;
    if ((((((((0x10 < iVar7) && (iVar8 = 3, 0x20 < iVar7)) && (iVar8 = 4, 0x30 < iVar7)) &&
           ((iVar8 = 5, 0x40 < iVar7 && (iVar8 = 6, 0x60 < iVar7)))) &&
          ((iVar8 = 7, 0x80 < iVar7 && ((iVar8 = 8, 0xa0 < iVar7 && (iVar8 = 9, 0xc0 < iVar7))))))
         && (iVar8 = 10, 0x100 < iVar7)) &&
        (((iVar8 = 0xb, 0x140 < iVar7 && (iVar8 = 0xc, 0x200 < iVar7)) &&
         (iVar8 = 0xd, 0x400 < iVar7)))) &&
       (((iVar8 = 0xe, 0x800 < iVar7 && (iVar8 = 0xf, 0x1000 < iVar7)) &&
        (iVar8 = 0x10, 0x2000 < iVar7)))) {
      trapWord(0x1f,&stack0xffffffffffffff20,&stack0xffffffffffffff20);
      iVar8 = -1;
    }
    lVar9 = (8 - uVar5 & 0xffffffff) + 1;
    if (8 < (int)uVar5) {
      lVar9 = 1;
    }
    *(int *)(uVar1 + (long)(iVar8 * 4 + 0xb0)) = iVar7;
    lVar6 = (uVar5 + 1 & 0x3fffff) << 10;
    *(int *)(uVar1 + (long)((int)((uVar4 & 0xffffffff) << 2) + 0x2f0) + 8) = iVar8;
    iVar8 = (int)lVar6;
    uVar2 = uVar5 + 1;
    uVar4 = uVar5;
    while( true ) {
      uVar5 = uVar2;
      lVar9 = lVar9 + -1;
      if (lVar9 == 0) {
        return;
      }
      if (8 < iVar8) break;
      *(int *)(uVar1 + 0xb4) = (int)lVar6;
      lVar6 = (uVar5 + 1 & 0x3fffff) << 10;
      *(undefined4 *)(uVar1 + (long)((int)((uVar4 & 0xffffffff) << 2) + 0x2f0) + 8) = 1;
      iVar8 = (int)lVar6;
      uVar2 = uVar5 + 1;
      uVar4 = uVar5;
    }
  } while( true );
}



// ===== function 0x284af0 =====

undefined8 FUN_00284af0(uint *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar6;
  undefined4 *puVar3;
  uint *puVar4;
  uint uVar7;
  uint *puVar5;
  uint uVar8;
  uint uVar10;
  uint *puVar9;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  bool bVar16;
  ulong uVar17;
  uint uVar18;
  ulong uVar19;
  uint uVar20;
  uint uVar21;
  ulong uVar22;
  undefined1 uVar23;
  undefined8 in_LR;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  undefined1 auStack_b4 [4];
  uint uStack_b0;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined1 auStack_98 [4];
  uint uStack_94;
  undefined4 uStack_84;
  uint uStack_80;
  uint uStack_70;
  uint uStack_6c;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint auStack_58 [4];
  
  if (*param_1 != 0) {
    return in_LR;
  }
  uVar6 = func_0x0071b0b8(0xc);
  puVar3 = (undefined4 *)func_0x0071b0b8(0x1c);
  if ((int)puVar3 != 0) {
    *puVar3 = 0;
  }
  if ((int)(puVar3 + 1) != 0) {
    puVar3[1] = 0;
  }
  if ((int)(puVar3 + 2) != 0) {
    puVar3[2] = 0;
  }
  uVar19 = (ulong)uVar6;
  uVar17 = (ulong)uRam0000000000e99b08;
  uVar21 = 0;
  *(undefined1 *)(puVar3 + 6) = 1;
  *(int *)(uVar19 + 4) = (int)puVar3;
  *(undefined1 *)((long)puVar3 + 0x19) = 1;
  uVar20 = *(uint *)(uVar19 + 4);
  *(undefined4 *)(uVar19 + 8) = 0;
  *param_1 = uVar6;
  *(uint *)((ulong)uVar20 + 4) = uVar20;
  *(uint *)(ulong)*(uint *)(uVar19 + 4) = *(uint *)(uVar19 + 4);
  *(uint *)((ulong)*(uint *)(uVar19 + 4) + 8) = *(uint *)(uVar19 + 4);
LAB_00284bfc:
  do {
    uVar22 = (ulong)*param_1;
    uVar6 = *(uint *)(uVar22 + 4);
    uVar19 = ((ulong)uVar21 & 0xfffffff) * 0x10 + ((ulong)uVar21 & 0x3fffffff) * -4 + uVar17;
    puVar15 = (uint *)(uVar19 & 0xffffffff);
    puVar4 = (uint *)(uVar19 + 8 & 0xffffffff);
    uVar20 = *puVar15;
    uVar18 = puVar15[1];
    uVar8 = *(uint *)((ulong)uVar6 + 4);
    puVar15 = (uint *)(ulong)uVar6;
    while (puVar9 = (uint *)(ulong)uVar8, puVar12 = puVar15, *(char *)((long)puVar9 + 0x19) == '\0')
    {
      while (puVar15 = (uint *)(ulong)uVar8, (int)*puVar4 <= (int)puVar9[3]) {
        uVar8 = *puVar9;
        puVar9 = (uint *)(ulong)uVar8;
        puVar12 = puVar15;
        if (*(char *)((long)puVar9 + 0x19) != '\0') goto LAB_00284c70;
      }
      puVar15 = puVar12;
      uVar8 = puVar9[2];
    }
LAB_00284c70:
    uVar8 = (uint)puVar15;
    if ((uVar6 == uVar8) || ((int)*puVar4 < (int)puVar15[3])) {
      uStack_c0 = *puVar4;
      uStack_bc = 0;
      uStack_b8 = 0;
      if (*(int *)(uVar22 + 8) == 0) {
        func_0x00872128(&uStack_70,uVar22,1,*(undefined4 *)(uVar22 + 4),&uStack_c0);
        puVar15 = (uint *)(ulong)uStack_70;
      }
      else {
        uVar6 = *(uint *)(uVar22 + 4);
        if (*(uint *)(ulong)uVar6 == uVar8) {
          if ((int)puVar15[3] <= (int)uStack_c0) goto LAB_00284e98;
          func_0x00872128(&uStack_6c,uVar22,1,puVar15,&uStack_c0);
          puVar15 = (uint *)(ulong)uStack_6c;
        }
        else if (uVar6 == uVar8) {
          uVar19 = (ulong)((uint *)(ulong)uVar6)[2];
          if ((int)uStack_c0 <= *(int *)(uVar19 + 0xc)) goto LAB_00284e98;
          func_0x00872128(&uStack_68,uVar22,0,uVar19,&uStack_c0);
          puVar15 = (uint *)(ulong)uStack_68;
        }
        else {
          if ((int)uStack_c0 < (int)puVar15[3]) {
            if (*(char *)((long)puVar15 + 0x19) == '\0') {
              puVar9 = (uint *)(ulong)*puVar15;
              if (*(char *)((long)(ulong)*puVar15 + 0x19) != '\0') {
                uVar6 = puVar15[1];
                puVar9 = (uint *)(ulong)uVar6;
                puVar4 = puVar15;
                if ((*(char *)((long)puVar9 + 0x19) == '\0') &&
                   (puVar12 = (uint *)(ulong)uVar6, puVar4 = (uint *)(ulong)uVar6, *puVar9 == uVar8)
                   ) {
                  do {
                    uVar6 = puVar9[1];
                    puVar13 = (uint *)(ulong)uVar6;
                    puVar4 = puVar9;
                    if (*(char *)((long)puVar13 + 0x19) != '\0') break;
                    uVar7 = (uint)puVar12;
                    puVar12 = (uint *)(ulong)uVar6;
                    puVar9 = puVar13;
                    puVar4 = (uint *)(ulong)uVar6;
                  } while (*puVar13 == uVar7);
                }
                goto LAB_00284db8;
              }
              do {
                puVar4 = puVar9;
                puVar9 = (uint *)(ulong)puVar4[2];
              } while (*(char *)((long)(ulong)puVar4[2] + 0x19) == '\0');
              uVar6 = puVar4[3];
            }
            else {
              puVar4 = (uint *)(ulong)puVar15[2];
LAB_00284db8:
              uVar6 = puVar4[3];
            }
            if ((int)uVar6 < (int)uStack_c0) {
              if (*(char *)((ulong)puVar4[2] + 0x19) == '\0') {
                func_0x00872128(&uStack_60,uVar22,1,puVar15,&uStack_c0);
                puVar15 = (uint *)(ulong)uStack_60;
              }
              else {
                func_0x00872128(&uStack_64,uVar22,0,puVar4,&uStack_c0);
                puVar15 = (uint *)(ulong)uStack_64;
              }
              goto LAB_00284c8c;
            }
          }
          if ((int)uStack_c0 <= (int)puVar15[3]) {
LAB_00284e98:
            uVar6 = *(uint *)(uVar22 + 4);
            puVar15 = (uint *)(ulong)uVar6;
            bVar16 = true;
            uVar8 = ((uint *)(ulong)uVar6)[1];
            do {
              puVar4 = (uint *)(ulong)uVar8;
              cVar1 = *(char *)((long)puVar4 + 0x19);
              while( true ) {
                if (cVar1 != '\0') {
                  uVar8 = (uint)puVar15;
                  puVar9 = puVar15;
                  if (!bVar16) goto LAB_00284efc;
                  if (*(uint *)(ulong)uVar6 != uVar8) {
                    if (*(char *)((long)puVar15 + 0x19) != '\0') {
                      puVar9 = (uint *)(ulong)puVar15[2];
                      goto LAB_00284efc;
                    }
                    uVar19 = (ulong)*puVar15;
                    puVar4 = (uint *)(ulong)*puVar15;
                    if (*(char *)(uVar19 + 0x19) == '\0') goto LAB_00285218;
                    uVar7 = puVar15[1];
                    puVar4 = (uint *)(ulong)uVar7;
                    if ((*(char *)((long)puVar4 + 0x19) != '\0') ||
                       (puVar9 = (uint *)(ulong)uVar7, *puVar4 != uVar8)) goto LAB_00284efc;
                    goto LAB_002851ec;
                  }
                  puVar12 = (uint *)0x15555553;
                  if (0x15555553 < *(uint *)(uVar22 + 8)) {
                    uVar21 = 0;
                    param_1 = (uint *)((ulong)auStack_b4 & 0xffffffff);
                    uVar20 = 0xf;
                    uVar17 = 0xffffffffffffffff;
                    func_0x0074a310(param_1,uRam0000000000e99ae0 /* 'map/set<T> too long' */);
                    puVar3 = (undefined4 *)func_0x0071b3b8(0x20);
                    uVar18 = uRam0000000000e99ad0;
                    uVar19 = (ulong)(puVar3 + 1) & 0xffffffff;
                    *(uint *)((ulong)puVar3 & 0xffffffff) = uRam0000000000e99ad0;
                    *(undefined4 *)(uVar19 + 0x18) = 0xf;
                    *(undefined1 *)(uVar19 + 4) = 0;
                    *(undefined4 *)(uVar19 + 0x14) = 0;
                    func_0x0074a020(uVar19,param_1,0,0xffffffff);
                    *puVar3 = uRam0000000000e99ad4;
                    uVar22 = (ulong)uStack_9c;
                    if (0xf < uVar22) {
                      func_0x0071b0c8(uStack_b0);
                    }
                    puVar15 = (uint *)(ulong)uRam0000000000e99ae8;
                    puVar9 = (uint *)(ulong)uRam0000000000e99ae4;
                    puVar13 = (uint *)0xf;
                    uStack_b0 = uStack_b0 & 0xffffff;
                    uStack_9c = 0xf;
                    uStack_a0 = 0;
                    uVar6 = func_0x0071b3c8((uint *)((ulong)puVar3 & 0xffffffff));
                    goto LAB_00285920;
                  }
                  puVar4 = (uint *)func_0x0071b0b8(0x1c);
                  uVar7 = (uint)puVar4;
                  if (uVar7 != 0) {
                    puVar9 = (uint *)((ulong)puVar4 & 0xffffffff);
                    puVar9[3] = uStack_c0;
                    puVar9[2] = uVar6;
                    puVar9[4] = uStack_bc;
                    *puVar9 = uVar6;
                    *(undefined1 *)((long)puVar9 + 0x19) = 0;
                    puVar9[5] = uStack_b8;
                    puVar9[1] = uVar8;
                    *(undefined1 *)(puVar9 + 6) = 0;
                  }
                  *(int *)(uVar22 + 8) = *(int *)(uVar22 + 8) + 1;
                  if (*(uint *)(uVar22 + 4) == uVar8) {
                    puVar15[1] = uVar7;
                    *(uint *)(ulong)*(uint *)(uVar22 + 4) = uVar7;
                    *(uint *)((ulong)*(uint *)(uVar22 + 4) + 8) = uVar7;
                  }
                  else {
                    *puVar15 = uVar7;
                    if (*(uint *)(ulong)*(uint *)(uVar22 + 4) == uVar8) {
                      *(uint *)(ulong)*(uint *)(uVar22 + 4) = uVar7;
                    }
                  }
                  puVar15 = (uint *)((ulong)puVar4 & 0xffffffff);
                  puVar3 = (undefined4 *)0x1;
                  puVar9 = puVar4;
                  goto LAB_00285368;
                }
                puVar15 = (uint *)(ulong)uVar8;
                if ((int)puVar4[3] <= (int)uStack_c0) break;
                uVar8 = *puVar4;
                bVar16 = true;
                puVar4 = (uint *)(ulong)uVar8;
                cVar1 = *(char *)((long)puVar4 + 0x19);
              }
              uVar8 = puVar4[2];
              bVar16 = false;
            } while( true );
          }
          puVar4 = puVar15;
          if (*(char *)((long)puVar15 + 0x19) == '\0') {
            uVar6 = puVar15[2];
            puVar9 = (uint *)(ulong)uVar6;
            if (*(char *)((long)puVar9 + 0x19) == '\0') {
              do {
                puVar4 = (uint *)(ulong)uVar6;
                uVar6 = *puVar9;
                puVar9 = (uint *)(ulong)uVar6;
              } while (*(char *)((long)puVar9 + 0x19) == '\0');
            }
            else {
              puVar4 = (uint *)(ulong)puVar15[1];
              uVar19 = (ulong)puVar15[1];
              if ((*(char *)(uVar19 + 0x19) == '\0') && (*(uint *)(uVar19 + 8) == uVar8)) {
                do {
                  iVar2 = (int)puVar4;
                  puVar4 = (uint *)(ulong)*(uint *)(uVar19 + 4);
                  uVar19 = (ulong)*(uint *)(uVar19 + 4);
                  if (*(char *)(uVar19 + 0x19) != '\0') break;
                } while (*(int *)(uVar19 + 8) == iVar2);
              }
            }
          }
          if ((*(int *)(uVar22 + 4) != (int)puVar4) && ((int)puVar4[3] <= (int)uStack_c0))
          goto LAB_00284e98;
          if (*(char *)((ulong)puVar15[2] + 0x19) == '\0') {
            func_0x00872128(auStack_58,uVar22,1,puVar4,&uStack_c0);
            puVar15 = (uint *)(ulong)auStack_58[0];
          }
          else {
            func_0x00872128(&uStack_5c,uVar22,0,puVar15,&uStack_c0);
            puVar15 = (uint *)(ulong)uStack_5c;
          }
        }
      }
    }
LAB_00284c8c:
    bVar16 = uVar21 != 0x5e;
    puVar15[4] = uVar20;
    uVar21 = uVar21 + 1;
    puVar15[5] = uVar18;
  } while (bVar16);
  goto LAB_00284cac;
LAB_00285218:
  do {
    puVar9 = puVar4;
    puVar4 = (uint *)(ulong)*(uint *)(uVar19 + 8);
    uVar19 = (ulong)*(uint *)(uVar19 + 8);
  } while (*(char *)(uVar19 + 0x19) == '\0');
  goto LAB_00284efc;
  while (uVar10 = (uint)puVar9, puVar9 = (uint *)(ulong)uVar7, *puVar4 == uVar10) {
LAB_002851ec:
    uVar7 = puVar4[1];
    puVar4 = (uint *)(ulong)uVar7;
    if (*(char *)((long)puVar4 + 0x19) != '\0') break;
  }
LAB_00284efc:
  if ((int)puVar9[3] < (int)uStack_c0) {
    puVar12 = (uint *)0x15555553;
    if (0x15555553 < *(uint *)(uVar22 + 8)) {
      uVar21 = 0;
      param_1 = (uint *)((ulong)auStack_98 & 0xffffffff);
      uVar20 = 0xf;
      uVar17 = 0xffffffffffffffff;
      func_0x0074a310(param_1,uRam0000000000e99ae0 /* 'map/set<T> too long' */);
      puVar3 = (undefined4 *)func_0x0071b3b8(0x20);
      uVar18 = uRam0000000000e99ad0;
      puVar15 = (uint *)((ulong)puVar3 & 0xffffffff);
      uVar19 = (ulong)(puVar3 + 1) & 0xffffffff;
      *puVar15 = uRam0000000000e99ad0;
      *(undefined4 *)(uVar19 + 0x18) = 0xf;
      *(undefined1 *)(uVar19 + 4) = 0;
      *(undefined4 *)(uVar19 + 0x14) = 0;
      func_0x0074a020(uVar19,param_1,0,0xffffffff);
      *puVar3 = uRam0000000000e99ad4;
      uVar22 = (ulong)uStack_80;
      if (0xf < uVar22) {
        func_0x0071b0c8(uStack_94);
      }
      puVar13 = (uint *)(ulong)uRam0000000000e99ae8;
      puVar11 = (uint *)0xf;
      puVar9 = (uint *)(ulong)uRam0000000000e99ae4;
      uStack_80 = 0xf;
      uStack_94 = uStack_94 & 0xffffff;
      uStack_84 = 0;
      uVar6 = func_0x0071b3c8(puVar15);
      goto LAB_00285868;
    }
    puVar4 = (uint *)func_0x0071b0b8(0x1c);
    uVar7 = (uint)puVar4;
    if (uVar7 != 0) {
      puVar9 = (uint *)((ulong)puVar4 & 0xffffffff);
      puVar9[3] = uStack_c0;
      puVar9[2] = uVar6;
      puVar9[4] = uStack_bc;
      *puVar9 = uVar6;
      *(undefined1 *)((long)puVar9 + 0x19) = 0;
      puVar9[5] = uStack_b8;
      puVar9[1] = uVar8;
      *(undefined1 *)(puVar9 + 6) = 0;
    }
    *(int *)(uVar22 + 8) = *(int *)(uVar22 + 8) + 1;
    if (*(uint *)(uVar22 + 4) == uVar8) {
      puVar15[1] = uVar7;
      *(uint *)(ulong)*(uint *)(uVar22 + 4) = uVar7;
      *(uint *)((ulong)*(uint *)(uVar22 + 4) + 8) = uVar7;
    }
    else if (bVar16) {
      *puVar15 = uVar7;
      if (*(uint *)(ulong)*(uint *)(uVar22 + 4) == uVar8) {
        *(uint *)(ulong)*(uint *)(uVar22 + 4) = uVar7;
      }
    }
    else {
      puVar15[2] = uVar7;
      if (*(uint *)((ulong)*(uint *)(uVar22 + 4) + 8) == uVar8) {
        *(uint *)((ulong)*(uint *)(uVar22 + 4) + 8) = uVar7;
      }
    }
    puVar3 = (undefined4 *)0x1;
    puVar14 = (uint *)((ulong)puVar4 & 0xffffffff);
    puVar15 = (uint *)0x0;
    puVar9 = puVar4;
    do {
      uVar8 = puVar14[1];
      puVar12 = (uint *)(ulong)uVar8;
      cVar1 = *(char *)(puVar12 + 6);
      puVar5 = puVar4;
      puVar13 = puVar14;
      while( true ) {
        if (cVar1 != '\0') goto LAB_00285078;
        puVar11 = (uint *)(ulong)uVar8;
        uVar7 = puVar12[1];
        puVar4 = (uint *)(ulong)uVar7;
        puVar14 = (uint *)(ulong)uVar7;
        uVar6 = (uint)puVar5;
        uVar23 = SUB81(puVar3,0);
        if (uVar8 == *puVar14) break;
        uVar19 = (ulong)*puVar14;
        if (*(char *)(uVar19 + 0x18) == '\0') goto LAB_002850c0;
        if (*puVar12 == uVar6) {
          uVar10 = puVar13[2];
          *puVar12 = uVar10;
          if (*(char *)((ulong)uVar10 + 0x19) == '\0') {
            *(uint *)((ulong)uVar10 + 4) = uVar8;
            uVar7 = puVar12[1];
          }
          puVar13[1] = uVar7;
          if (*(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) == uVar8) {
            *(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) = uVar6;
          }
          else {
            puVar4 = (uint *)(ulong)puVar12[1];
            if (puVar4[2] == uVar8) {
              puVar4[2] = uVar6;
            }
            else {
              *puVar4 = uVar6;
            }
          }
          puVar12[1] = uVar6;
          puVar13[2] = uVar8;
          puVar5 = puVar11;
          puVar13 = puVar11;
        }
        uVar6 = *(uint *)((ulong)puVar13[1] + 4);
        *(undefined1 *)((ulong)puVar13[1] + 0x18) = uVar23;
        uVar19 = (ulong)uVar6;
        uVar8 = *(uint *)(uVar19 + 8);
        *(char *)(uVar19 + 0x18) = (char)puVar15;
        puVar4 = (uint *)(ulong)uVar8;
        uVar7 = *puVar4;
        *(uint *)(uVar19 + 8) = uVar7;
        if (*(char *)((ulong)uVar7 + 0x19) == '\0') {
          *(uint *)((ulong)uVar7 + 4) = uVar6;
        }
        puVar4[1] = *(uint *)(uVar19 + 4);
        if (*(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) == uVar6) {
          *(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) = uVar8;
        }
        else {
          puVar12 = (uint *)(ulong)*(uint *)(uVar19 + 4);
          if (*puVar12 == uVar6) {
            *puVar12 = uVar8;
          }
          else {
            puVar12[2] = uVar8;
          }
        }
        *(uint *)(uVar19 + 4) = uVar8;
        *puVar4 = uVar6;
        uVar8 = puVar13[1];
        puVar12 = (uint *)(ulong)uVar8;
        cVar1 = *(char *)(puVar12 + 6);
      }
      uVar19 = (ulong)puVar14[2];
      if (*(char *)(uVar19 + 0x18) == '\0') {
LAB_002850c0:
        *(undefined1 *)(puVar12 + 6) = uVar23;
        *(undefined1 *)(uVar19 + 0x18) = uVar23;
        *(undefined1 *)(puVar14 + 6) = 0;
      }
      else {
        puVar4 = puVar5;
        puVar14 = puVar13;
        if (puVar12[2] == uVar6) {
          uVar10 = *puVar13;
          puVar12[2] = uVar10;
          if (*(char *)((ulong)uVar10 + 0x19) == '\0') {
            *(uint *)((ulong)uVar10 + 4) = uVar8;
            uVar7 = puVar12[1];
          }
          puVar13[1] = uVar7;
          puVar4 = (uint *)(ulong)*(uint *)(uVar22 + 4);
          if (puVar4[1] == uVar8) {
LAB_00285868:
            puVar4[1] = uVar6;
            puVar4 = puVar11;
          }
          else {
            puVar14 = (uint *)(ulong)puVar12[1];
            puVar4 = puVar11;
            if (*puVar14 == uVar8) {
              *puVar14 = uVar6;
            }
            else {
              puVar14[2] = uVar6;
            }
          }
          puVar12[1] = uVar6;
          *puVar13 = (uint)puVar4;
          puVar14 = (uint *)((ulong)puVar4 & 0xffffffff);
        }
        uVar6 = *(uint *)((ulong)puVar14[1] + 4);
        *(char *)((ulong)puVar14[1] + 0x18) = (char)puVar3;
        puVar12 = (uint *)(ulong)uVar6;
        uVar8 = *puVar12;
        *(char *)(puVar12 + 6) = (char)puVar15;
        uVar19 = (ulong)uVar8;
        uVar7 = *(uint *)(uVar19 + 8);
        *puVar12 = uVar7;
        if (*(char *)((ulong)uVar7 + 0x19) == '\0') {
          *(uint *)((ulong)uVar7 + 4) = uVar6;
        }
        *(uint *)(uVar19 + 4) = puVar12[1];
        if (*(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) == uVar6) {
          *(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) = uVar8;
        }
        else {
          puVar13 = (uint *)(ulong)puVar12[1];
          if (puVar13[2] == uVar6) {
            puVar13[2] = uVar8;
          }
          else {
            *puVar13 = uVar8;
          }
        }
        *(uint *)(uVar19 + 8) = uVar6;
        puVar12[1] = uVar8;
      }
    } while( true );
  }
LAB_00285088:
  bVar16 = uVar21 == 0x5e;
  uVar21 = uVar21 + 1;
  *(uint *)(((ulong)puVar9 & 0xffffffff) + 0x10) = uVar20;
  *(uint *)(((ulong)puVar9 & 0xffffffff) + 0x14) = uVar18;
  if (bVar16) {
LAB_00284cac:
    func_0x0027c1b8(uRam0000000000e99b0c /* 'Message map created' */);
    return in_LR;
  }
  goto LAB_00284bfc;
LAB_00285368:
  uVar6 = puVar15[1];
  puVar13 = (uint *)(ulong)uVar6;
  puVar12 = (uint *)(ulong)uVar6;
  if (*(char *)(puVar12 + 6) == '\0') {
    puVar14 = (uint *)(ulong)puVar12[1];
    puVar11 = (uint *)(ulong)puVar12[1];
    uVar8 = *puVar11;
    uVar23 = SUB81(puVar3,0);
    if (uVar6 != uVar8) {
      do {
        uVar19 = (ulong)uVar8;
        uVar6 = (uint)puVar14;
        if (*(char *)(uVar19 + 0x18) == '\0') goto LAB_002854d4;
        uVar8 = (uint)puVar4;
        if (*puVar12 == uVar8) {
          uVar7 = puVar15[2];
          *puVar12 = uVar7;
          uVar10 = (uint)puVar13;
          if (*(char *)((ulong)uVar7 + 0x19) == '\0') {
            *(uint *)((ulong)uVar7 + 4) = uVar10;
            uVar6 = puVar12[1];
          }
          puVar15[1] = uVar6;
          if (*(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) == uVar10) {
            *(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) = uVar8;
          }
          else {
            puVar4 = (uint *)(ulong)puVar12[1];
            if (puVar4[2] == uVar10) {
              puVar4[2] = uVar8;
            }
            else {
              *puVar4 = uVar8;
            }
          }
          puVar12[1] = uVar8;
          puVar15[2] = uVar10;
          puVar4 = puVar13;
          puVar15 = puVar13;
        }
        uVar6 = *(uint *)((ulong)puVar15[1] + 4);
        *(undefined1 *)((ulong)puVar15[1] + 0x18) = uVar23;
        uVar19 = (ulong)uVar6;
        uVar8 = *(uint *)(uVar19 + 8);
        *(undefined1 *)(uVar19 + 0x18) = 0;
        puVar12 = (uint *)(ulong)uVar8;
        uVar7 = *puVar12;
        *(uint *)(uVar19 + 8) = uVar7;
        if (*(char *)((ulong)uVar7 + 0x19) == '\0') {
          *(uint *)((ulong)uVar7 + 4) = uVar6;
        }
        puVar12[1] = *(uint *)(uVar19 + 4);
        if (*(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) == uVar6) {
          *(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) = uVar8;
        }
        else {
          puVar13 = (uint *)(ulong)*(uint *)(uVar19 + 4);
          if (*puVar13 == uVar6) {
            *puVar13 = uVar8;
          }
          else {
            puVar13[2] = uVar8;
          }
        }
        *(uint *)(uVar19 + 4) = uVar8;
        *puVar12 = uVar6;
        uVar6 = puVar15[1];
        puVar13 = (uint *)(ulong)uVar6;
        puVar12 = (uint *)(ulong)uVar6;
        if (*(char *)(puVar12 + 6) != '\0') goto LAB_00285078;
        puVar14 = (uint *)(ulong)puVar12[1];
        puVar11 = (uint *)(ulong)puVar12[1];
        uVar8 = *puVar11;
      } while (uVar6 != uVar8);
    }
    uVar6 = (uint)puVar4;
    uVar8 = (uint)puVar14;
    uVar19 = (ulong)puVar11[2];
    if (*(char *)(uVar19 + 0x18) == '\0') {
LAB_002854d4:
      puVar4 = puVar14;
      puVar15 = puVar11;
      *(undefined1 *)(puVar12 + 6) = uVar23;
      *(undefined1 *)(uVar19 + 0x18) = uVar23;
      *(undefined1 *)(puVar15 + 6) = 0;
    }
    else {
      if (puVar12[2] == uVar6) {
        uVar7 = *puVar15;
        puVar12[2] = uVar7;
        uVar10 = (uint)puVar13;
        if (*(char *)((ulong)uVar7 + 0x19) == '\0') {
          *(uint *)((ulong)uVar7 + 4) = uVar10;
          uVar8 = puVar12[1];
        }
        puVar15[1] = uVar8;
        puVar4 = (uint *)(ulong)*(uint *)(uVar22 + 4);
        if (puVar4[1] == uVar10) {
LAB_00285920:
          puVar4[1] = uVar6;
          puVar4 = puVar13;
        }
        else {
          puVar11 = (uint *)(ulong)puVar12[1];
          puVar4 = puVar13;
          if (*puVar11 == uVar10) {
            *puVar11 = uVar6;
          }
          else {
            puVar11[2] = uVar6;
          }
        }
        puVar12[1] = uVar6;
        *puVar15 = (uint)puVar4;
        puVar15 = (uint *)((ulong)puVar4 & 0xffffffff);
      }
      uVar6 = *(uint *)((ulong)puVar15[1] + 4);
      *(char *)((ulong)puVar15[1] + 0x18) = (char)puVar3;
      puVar12 = (uint *)(ulong)uVar6;
      uVar8 = *puVar12;
      *(undefined1 *)(puVar12 + 6) = 0;
      uVar19 = (ulong)uVar8;
      uVar7 = *(uint *)(uVar19 + 8);
      *puVar12 = uVar7;
      if (*(char *)((ulong)uVar7 + 0x19) == '\0') {
        *(uint *)((ulong)uVar7 + 4) = uVar6;
      }
      *(uint *)(uVar19 + 4) = puVar12[1];
      if (*(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) == uVar6) {
        *(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) = uVar8;
      }
      else {
        puVar13 = (uint *)(ulong)puVar12[1];
        if (puVar13[2] == uVar6) {
          puVar13[2] = uVar8;
        }
        else {
          *puVar13 = uVar8;
        }
      }
      *(uint *)(uVar19 + 8) = uVar6;
      puVar12[1] = uVar8;
    }
    goto LAB_00285368;
  }
LAB_00285078:
  *(undefined1 *)((ulong)*(uint *)((ulong)*(uint *)(uVar22 + 4) + 4) + 0x18) = 1;
  goto LAB_00285088;
}



// ===== function 0x284368 =====

void FUN_00284368(uint *param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  
  uVar8 = (ulong)*param_1;
  uVar10 = *(uint *)(uVar8 + 4);
  uVar9 = (ulong)uVar10;
  uVar4 = *(uint *)((ulong)uVar10 + 4);
LAB_002843a0:
  puVar3 = (uint *)(ulong)uVar4;
  cVar1 = *(char *)((long)puVar3 + 0x19);
  do {
    if (cVar1 != '\0') {
      if ((uVar10 == (uint)uVar9) || (param_2 < *(int *)(uVar9 + 0xc))) {
        if (*(uint *)(uVar8 + 4) == uVar10) goto LAB_002844b4;
        uVar9 = (ulong)uVar10;
        iVar7 = *(int *)(uVar9 + 0x10);
        if (iVar7 != 0) goto LAB_002844f4;
        uVar5 = func_0x0071b208();
        uVar6 = func_0x0071b328(uVar5,0x5dd);
        uVar5 = func_0x0071b338(uVar5,uVar6);
        iVar7 = func_0x0071b078(uVar5);
      }
      else {
        if ((*(uint *)(uVar8 + 4) != (uint)uVar9) && (iVar7 = *(int *)(uVar9 + 0x10), iVar7 != 0)) {
LAB_002844f4:
          iVar2 = *(int *)(uVar9 + 0x14);
          uVar5 = func_0x00283ff0((ulong)param_1 & 0xffffffff,(long)iVar7,param_2,iVar2);
          *param_3 = uVar5;
          uVar10 = 0x80;
          if (param_2 < 0x61) {
            uVar4 = 0xa0;
          }
          else {
            uVar10 = 0x81;
            uVar4 = 0xa1;
          }
          if ((iVar2 != 3) && (uVar4 = uVar10 | 0x10, iVar2 == 1)) {
            uVar4 = uVar10 | 0x110;
          }
          goto LAB_00284470;
        }
LAB_002844b4:
        uVar5 = func_0x0071b208();
        uVar6 = func_0x0071b328(uVar5,0x5dd);
        uVar5 = func_0x0071b338(uVar5,uVar6);
        iVar7 = func_0x0071b078(uVar5);
      }
      uVar6 = func_0x00bdf5b0(iVar7 + 10);
      *param_3 = uVar6;
      func_0x0071b048(uVar6,uVar5);
      uVar4 = 0xa0;
LAB_00284470:
      param_3[1] = uVar4;
      return;
    }
    uVar11 = (ulong)uVar4;
    if ((int)puVar3[3] < param_2) break;
    uVar4 = *puVar3;
    puVar3 = (uint *)(ulong)uVar4;
    cVar1 = *(char *)((long)puVar3 + 0x19);
    uVar9 = uVar11;
  } while( true );
  uVar4 = puVar3[2];
  goto LAB_002843a0;
}



