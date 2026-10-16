// ===== function 0x87ed48 =====

void FUN_0087ed48(long param_1)

{
  *(undefined1 *)(param_1 + 0xff8) = 1;
  return;
}



// ===== function 0x87ed58 =====

void FUN_0087ed58(long param_1)

{
  *(undefined1 *)(param_1 + 0xff8) = 0;
  return;
}



// ===== function 0x87ed68 =====

undefined1 FUN_0087ed68(long param_1)

{
  return *(undefined1 *)(param_1 + 0xff8);
}



// ===== function 0x884f58 =====

void FUN_00884f58(long param_1)

{
  int iVar1;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_20 = 1;
  uStack_1c = 1;
  iVar1 = func_0x0040b7c0(&uStack_20,2);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0xff4) = 2;
    return;
  }
  *(undefined4 *)(param_1 + 0xff4) = 1;
  return;
}



// ===== function 0x884fe0 =====

undefined4 FUN_00884fe0(undefined4 param_1,int param_2)

{
  func_0x00281688(param_1,param_2 + 0x7c0);
  return param_1;
}



// ===== function 0x869380 =====

void FUN_00869380(ulong param_1,ulong param_2,ulong param_3,ulong param_4)

{
  bool bVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  ulong uVar7;
  uint *puVar8;
  uint *puVar9;
  ulong uVar10;
  uint *puVar11;
  ulong uVar12;
  undefined *puVar13;
  uint *puVar14;
  undefined1 *puVar15;
  uint *puVar16;
  undefined1 *puVar17;
  int iVar19;
  undefined1 *puVar18;
  uint uVar20;
  uint uVar21;
  uint uVar23;
  ulong uVar22;
  int iVar24;
  uint *puVar25;
  uint uVar26;
  uint uVar28;
  ulong uVar27;
  undefined1 auStack_ae0 [4];
  uint auStack_adc [4];
  uint uStack_acc;
  uint uStack_ac8;
  undefined4 uStack_ac4;
  undefined1 uStack_ac0;
  byte bStack_abf;
  undefined1 auStack_abe [128];
  undefined1 auStack_a3e [130];
  undefined4 uStack_9bc;
  undefined1 auStack_9b8 [128];
  undefined1 auStack_938 [256];
  undefined4 uStack_838;
  undefined1 uStack_834;
  byte bStack_833;
  undefined1 auStack_832 [128];
  undefined1 auStack_7b2 [130];
  undefined4 uStack_730;
  undefined1 auStack_72c [128];
  undefined1 auStack_6ac [256];
  undefined4 uStack_5ac;
  undefined1 uStack_5a8;
  undefined1 uStack_5a7;
  undefined1 auStack_5a6 [128];
  undefined1 auStack_526 [130];
  undefined4 uStack_4a4;
  undefined1 auStack_4a0 [128];
  undefined1 auStack_420 [256];
  undefined4 uStack_320;
  undefined1 uStack_31c;
  byte bStack_31b;
  uint auStack_31a [32];
  undefined1 auStack_29a [130];
  undefined4 uStack_218;
  undefined1 auStack_214 [128];
  undefined1 auStack_194 [260];
  
  uVar5 = uRam0000000000e99840;
  uVar4 = uRam0000000000e9983c;
  puVar16 = auStack_31a;
  uVar12 = param_4 & 0xffffffff;
  bStack_31b = *(byte *)(param_4 + 5);
  puVar14 = (uint *)(ulong)bStack_31b;
  uStack_31c = *(undefined1 *)(param_4 + 4);
  puVar15 = auStack_29a;
  uStack_320 = uRam0000000000e99840;
  puVar17 = auStack_214;
  func_0x0071b098(puVar16,uVar12 + 6,0x80);
  puVar18 = auStack_194;
  func_0x0071b098(puVar15,uVar12 + 0x86,0x80);
  uStack_218 = *(undefined4 *)(param_4 + 0x108);
  func_0x0071b098(puVar17,uVar12 + 0x10c,0x80);
  func_0x0071b098(puVar18,uVar12 + 0x18c,0x100);
  iVar19 = *(int *)(param_1 + 4);
  bVar1 = iVar19 == 0;
  if (bVar1) {
    uVar12 = 0;
  }
  else {
    uVar12 = (long)(*(int *)(param_1 + 0xc) - iVar19 >> 2) * 0x451ab30b;
  }
  if ((int)param_3 != 0) {
    if (bVar1) {
      puVar13 = &UNK_006483ed;
    }
    else {
      puVar14 = (uint *)0x451a0000;
      puVar13 = &UNK_006483ed + (long)(*(int *)(param_1 + 8) - iVar19 >> 2) * -0x451ab30b;
    }
    if (((ulong)puVar13 & 0xffffffff) < (param_3 & 0xffffffff)) {
      func_0x0074a310(auStack_ae0,uRam0000000000e99a6c /* 'vector<T> too long' */);
      puVar15 = (undefined1 *)0x0;
      puVar8 = (uint *)func_0x0071b3b8(0x20);
      puVar17 = (undefined1 *)0xf;
      puVar18 = (undefined1 *)(ulong)uRam0000000000e999c0;
      puVar16 = puVar8 + 1;
      *puVar8 = uRam0000000000e999c0;
      uVar12 = (ulong)puVar16 & 0xffffffff;
      *(undefined4 *)(uVar12 + 0x14) = 0;
      *(undefined4 *)(uVar12 + 0x18) = 0xf;
      puVar25 = puVar8 + 2;
      *(undefined1 *)puVar25 = 0;
      if ((int)puVar16 != (int)auStack_ae0) {
        param_2 = func_0x00720a28(uVar12,uStack_acc,0);
        param_2 = param_2 & 0xff;
        if ((int)param_2 != 0) {
          puVar9 = puVar25;
          if (0xf < *(uint *)(uVar12 + 0x18)) {
            puVar9 = (uint *)(ulong)*(uint *)(uVar12 + 4);
          }
          puVar11 = auStack_adc;
          if (0xf < uStack_ac8) {
            puVar11 = (uint *)(ulong)auStack_adc[0];
          }
          func_0x0071b098((ulong)puVar9 & 0xffffffff,(ulong)puVar11 & 0xffffffff,uStack_acc);
          if (0xf < *(uint *)(uVar12 + 0x18)) {
            puVar25 = (uint *)(ulong)*(uint *)(uVar12 + 4);
          }
          *(uint *)(uVar12 + 0x14) = uStack_acc;
          *(undefined1 *)((ulong)((long)puVar25 + (ulong)uStack_acc) & 0xffffffff) = 0;
        }
      }
      uVar12 = (ulong)uRam0000000000e99a5c;
      *puVar8 = uRam0000000000e99a5c;
      param_1 = (ulong)uStack_ac8;
      if (0xf < param_1) {
        func_0x0071b0c8(auStack_adc[0]);
      }
      auStack_adc[0] = auStack_adc[0] & 0xffffff;
      uStack_ac8 = 0xf;
      uStack_acc = 0;
      func_0x0071b3c8((ulong)puVar8 & 0xffffffff,uRam0000000000e99a70,uRam0000000000e99a74);
    }
    else {
      if (bVar1) {
        lVar6 = 0;
      }
      else {
        lVar6 = (long)(*(int *)(param_1 + 8) - iVar19 >> 2) * 0x451ab30b;
      }
      uVar20 = (uint)param_2;
      if ((uVar12 & 0xffffffff) < (lVar6 + param_3 & 0xffffffff)) {
        uVar7 = (uVar12 & 0xffffffff) >> 1;
        uVar10 = 0;
        if ((uVar12 & 0xffffffff) <= ((long)&UNK_006483ed - uVar7 & 0xffffffff)) {
          uVar10 = uVar12 + uVar7;
        }
        if (bVar1) {
          lVar6 = 0;
        }
        else {
          lVar6 = (long)(*(int *)(param_1 + 8) - iVar19 >> 2) * 0x451ab30b;
        }
        if ((uVar10 & 0xffffffff) < (lVar6 + param_3 & 0xffffffff)) {
          if (bVar1) {
            lVar6 = 0;
          }
          else {
            lVar6 = (long)(*(int *)(param_1 + 8) - iVar19 >> 2) * 0x451ab30b;
          }
          uVar10 = lVar6 + param_3;
        }
        uVar7 = func_0x0071b0b8(uVar10 * 0x28c & 0xffffffff);
        uVar12 = uVar7;
        for (uVar23 = *(uint *)(param_1 + 4); uVar20 != uVar23; uVar23 = uVar23 + 0x28c) {
          while ((int)uVar12 == 0) {
            uVar23 = uVar23 + 0x28c;
            uVar12 = 0x28c;
            if (uVar20 == uVar23) {
              uVar12 = 0x28c;
              goto LAB_00869a08;
            }
          }
          uVar22 = (ulong)uVar23;
          puVar3 = (undefined4 *)(uVar12 & 0xffffffff);
          uVar2 = *(undefined1 *)(uVar22 + 5);
          uVar12 = uVar12 + 0x28c;
          *(undefined1 *)(puVar3 + 1) = *(undefined1 *)(uVar22 + 4);
          *(undefined1 *)((long)puVar3 + 5) = uVar2;
          *puVar3 = uVar5;
          func_0x0071b098((long)puVar3 + 6,uVar22 + 6,0x80);
          func_0x0071b098((long)puVar3 + 0x86,uVar22 + 0x86,0x80);
          puVar3[0x42] = *(undefined4 *)(uVar22 + 0x108);
          func_0x0071b098(puVar3 + 0x43,uVar22 + 0x10c,0x80);
          func_0x0071b098(puVar3 + 99,uVar22 + 0x18c,0x100);
        }
LAB_00869a08:
        uVar22 = param_3;
        uVar27 = uVar12;
        if ((int)uVar12 == 0) goto LAB_00869aa0;
        do {
          puVar3 = (undefined4 *)(uVar27 & 0xffffffff);
          uVar22 = uVar22 - 1;
          *(undefined1 *)(puVar3 + 1) = uStack_31c;
          *(byte *)((long)puVar3 + 5) = bStack_31b;
          *puVar3 = uVar5;
          func_0x0071b098((long)puVar3 + 6,(ulong)puVar16 & 0xffffffff,0x80);
          func_0x0071b098((long)puVar3 + 0x86,(ulong)puVar15 & 0xffffffff,0x80);
          puVar3[0x42] = uStack_218;
          func_0x0071b098(puVar3 + 0x43,(ulong)puVar17 & 0xffffffff,0x80);
          func_0x0071b098(puVar3 + 99,(ulong)puVar18 & 0xffffffff,0x100);
          iVar19 = (int)uVar22;
          while( true ) {
            if (iVar19 == 0) {
              uVar23 = *(uint *)(param_1 + 8);
              iVar19 = (int)(param_3 * 0x28c);
              uVar12 = param_3 * 0x28c + uVar12;
              if (uVar20 != uVar23) goto LAB_00869ac0;
              goto LAB_00869c08;
            }
            uVar27 = uVar27 + 0x28c;
            if ((int)uVar27 != 0) break;
LAB_00869aa0:
            uVar22 = uVar22 - 1;
            iVar19 = (int)uVar22;
          }
        } while( true );
      }
      uVar23 = *(uint *)(param_1 + 8);
      puVar14 = (uint *)(ulong)uVar23;
      puVar8 = puVar14;
      uVar12 = param_2;
      if ((param_3 & 0xffffffff) <= ((long)((int)(uVar23 - uVar20) >> 2) * 0x451ab30b & 0xffffffffU)
         ) {
        puVar9 = puVar14 + param_3 * -0xa3;
        uVar21 = (uint)puVar9;
        puVar25 = puVar14;
        puVar8 = puVar9;
        uVar26 = uVar21;
        uVar28 = uVar21;
        while (uVar23 != uVar28) {
          if ((int)puVar25 != 0) {
            uVar12 = (ulong)puVar8 & 0xffffffff;
            puVar3 = (undefined4 *)((ulong)puVar25 & 0xffffffff);
            uVar2 = *(undefined1 *)(uVar12 + 5);
            *(undefined1 *)(puVar3 + 1) = *(undefined1 *)(uVar12 + 4);
            *(undefined1 *)((long)puVar3 + 5) = uVar2;
            *puVar3 = uVar5;
            func_0x0071b098((long)puVar3 + 6,uVar12 + 6,0x80);
            func_0x0071b098((long)puVar3 + 0x86,uVar12 + 0x86,0x80);
            puVar3[0x42] = *(undefined4 *)(uVar12 + 0x108);
            func_0x0071b098(puVar3 + 0x43,uVar12 + 0x10c,0x80);
            func_0x0071b098(puVar3 + 99,uVar12 + 0x18c,0x100);
          }
          puVar8 = puVar8 + 0xa3;
          puVar25 = puVar25 + 0xa3;
          uVar26 = (uint)puVar25;
          uVar28 = (uint)puVar8;
        }
        *(uint *)(param_1 + 8) = uVar26;
        if (uVar20 != uVar21) {
          do {
            puVar9 = puVar9 + -0xa3;
            uVar12 = (ulong)puVar9 & 0xffffffff;
            uStack_5ac = uVar5;
            puVar14 = puVar14 + -0xa3;
            uStack_5a8 = *(undefined1 *)(uVar12 + 4);
            uStack_5a7 = *(undefined1 *)(uVar12 + 5);
            func_0x0071b098((ulong)auStack_5a6 & 0xffffffff,uVar12 + 6,0x80);
            func_0x0071b098((ulong)auStack_526 & 0xffffffff,uVar12 + 0x86,0x80);
            uStack_4a4 = *(undefined4 *)(uVar12 + 0x108);
            func_0x0071b098((ulong)auStack_4a0 & 0xffffffff,uVar12 + 0x10c,0x80);
            func_0x0071b098((ulong)auStack_420 & 0xffffffff,uVar12 + 0x18c,0x100);
            func_0x0071b098((ulong)puVar14 & 0xffffffff,(ulong)&uStack_5ac & 0xffffffff,0x28c);
            uStack_5ac = uVar4;
          } while (uVar20 != (uint)puVar9);
        }
        lVar6 = param_2 + param_3 * 0x28c;
        uVar23 = (uint)lVar6;
        if (uVar20 != uVar23) {
          uStack_ac0 = uStack_31c;
          bStack_abf = bStack_31b;
          uStack_ac4 = uVar5;
          func_0x0071b098((ulong)auStack_abe & 0xffffffff,(ulong)puVar16 & 0xffffffff,0x80);
          func_0x0071b098((ulong)auStack_a3e & 0xffffffff,(ulong)puVar15 & 0xffffffff,0x80);
          uStack_9bc = uStack_218;
          func_0x0071b098((ulong)auStack_9b8 & 0xffffffff,(ulong)puVar17 & 0xffffffff,0x80);
          uVar12 = param_2 + 0x28c;
          func_0x0071b098((ulong)auStack_938 & 0xffffffff,(ulong)puVar18 & 0xffffffff,0x100);
          func_0x0071b098(param_2 & 0xffffffff,(ulong)&uStack_ac4 & 0xffffffff,0x28c);
          if (uVar23 != (uint)uVar12) {
            if (((lVar6 - param_2) - 0x28c >> 2 & 1) != 0) {
              uStack_ac0 = uStack_31c;
              bStack_abf = bStack_31b;
              uStack_ac4 = uVar5;
              func_0x0071b098((ulong)auStack_abe & 0xffffffff,(ulong)puVar16 & 0xffffffff,0x80);
              func_0x0071b098((ulong)auStack_a3e & 0xffffffff,(ulong)puVar15 & 0xffffffff,0x80);
              uStack_9bc = uStack_218;
              func_0x0071b098((ulong)auStack_9b8 & 0xffffffff,(ulong)puVar17 & 0xffffffff,0x80);
              func_0x0071b098((ulong)auStack_938 & 0xffffffff,(ulong)puVar18 & 0xffffffff,0x100);
              goto LAB_008698c4;
            }
            do {
              uStack_ac0 = uStack_31c;
              bStack_abf = bStack_31b;
              uStack_ac4 = uVar5;
              func_0x0071b098((ulong)auStack_abe & 0xffffffff,(ulong)puVar16 & 0xffffffff,0x80);
              func_0x0071b098((ulong)auStack_a3e & 0xffffffff,(ulong)puVar15 & 0xffffffff,0x80);
              uStack_9bc = uStack_218;
              func_0x0071b098((ulong)auStack_9b8 & 0xffffffff,(ulong)puVar17 & 0xffffffff,0x80);
              func_0x0071b098((ulong)auStack_938 & 0xffffffff,(ulong)puVar18 & 0xffffffff,0x100);
              func_0x0071b098(uVar12 & 0xffffffff,(ulong)&uStack_ac4 & 0xffffffff,0x28c);
              uStack_ac0 = uStack_31c;
              bStack_abf = bStack_31b;
              uStack_ac4 = uVar5;
              func_0x0071b098((ulong)auStack_abe & 0xffffffff,(ulong)puVar16 & 0xffffffff,0x80);
              func_0x0071b098((ulong)auStack_a3e & 0xffffffff,(ulong)puVar15 & 0xffffffff,0x80);
              uStack_9bc = uStack_218;
              func_0x0071b098((ulong)auStack_9b8 & 0xffffffff,(ulong)puVar17 & 0xffffffff,0x80);
              func_0x0071b098((ulong)auStack_938 & 0xffffffff,(ulong)puVar18 & 0xffffffff,0x100);
              param_2 = uVar12;
              uVar12 = uVar12 + 0x28c;
LAB_008698c4:
              uVar7 = uVar12 & 0xffffffff;
              uVar12 = param_2 + 0x518;
              func_0x0071b098(uVar7,(ulong)&uStack_ac4 & 0xffffffff,0x28c);
            } while (uVar23 != (uint)uVar12);
          }
        }
        goto LAB_008694a0;
      }
    }
    iVar19 = (int)param_2;
    uVar7 = param_2 + param_3 * 0x28c;
    if (iVar19 != (int)puVar14) {
      while( true ) {
        iVar24 = (int)uVar7;
        while (iVar24 != 0) {
          uVar10 = param_2 & 0xffffffff;
          puVar3 = (undefined4 *)(uVar7 & 0xffffffff);
          param_2 = param_2 + 0x28c;
          uVar2 = *(undefined1 *)(uVar10 + 5);
          *(undefined1 *)(puVar3 + 1) = *(undefined1 *)(uVar10 + 4);
          *(undefined1 *)((long)puVar3 + 5) = uVar2;
          *puVar3 = uVar5;
          func_0x0071b098((long)puVar3 + 6,uVar10 + 6,0x80);
          func_0x0071b098((long)puVar3 + 0x86,uVar10 + 0x86,0x80);
          puVar3[0x42] = *(undefined4 *)(uVar10 + 0x108);
          func_0x0071b098(puVar3 + 0x43,uVar10 + 0x10c,0x80);
          func_0x0071b098(puVar3 + 99,uVar10 + 0x18c,0x100);
          if ((int)puVar8 == (int)param_2) goto LAB_00869fe0;
          uVar7 = uVar7 + 0x28c;
          iVar24 = (int)uVar7;
        }
        param_2 = param_2 + 0x28c;
        if ((int)puVar8 == (int)param_2) break;
        uVar7 = 0x28c;
      }
LAB_00869fe0:
      puVar14 = (uint *)(ulong)*(uint *)(param_1 + 8);
    }
    lVar6 = param_3 + (long)((int)puVar14 - iVar19 >> 2) * -0x451ab30b;
    if ((int)lVar6 != 0) {
      while( true ) {
        iVar24 = (int)puVar14;
        while (iVar24 != 0) {
          puVar3 = (undefined4 *)((ulong)puVar14 & 0xffffffff);
          lVar6 = lVar6 + -1;
          *(undefined1 *)(puVar3 + 1) = uStack_31c;
          *(byte *)((long)puVar3 + 5) = bStack_31b;
          *puVar3 = uVar5;
          func_0x0071b098((long)puVar3 + 6,(ulong)puVar16 & 0xffffffff,0x80);
          func_0x0071b098((long)puVar3 + 0x86,(ulong)puVar15 & 0xffffffff,0x80);
          puVar3[0x42] = uStack_218;
          func_0x0071b098(puVar3 + 0x43,(ulong)puVar17 & 0xffffffff,0x80);
          func_0x0071b098(puVar3 + 99,(ulong)puVar18 & 0xffffffff,0x100);
          if ((int)lVar6 == 0) goto LAB_0086a0ac;
          puVar14 = puVar14 + 0xa3;
          iVar24 = (int)puVar14;
        }
        lVar6 = lVar6 + -1;
        if ((int)lVar6 == 0) break;
        puVar14 = (uint *)0x28c;
      }
LAB_0086a0ac:
      puVar14 = (uint *)(ulong)*(uint *)(param_1 + 8);
    }
    puVar14 = puVar14 + param_3 * 0xa3;
    *(int *)(param_1 + 8) = (int)puVar14;
    iVar24 = (int)(puVar14 + param_3 * -0xa3);
    if (iVar19 != iVar24) {
      uStack_834 = uStack_31c;
      bStack_833 = bStack_31b;
      uStack_838 = uVar5;
      func_0x0071b098((ulong)auStack_832 & 0xffffffff,(ulong)puVar16 & 0xffffffff,0x80);
      func_0x0071b098((ulong)auStack_7b2 & 0xffffffff,(ulong)puVar15 & 0xffffffff,0x80);
      uStack_730 = uStack_218;
      func_0x0071b098((ulong)auStack_72c & 0xffffffff,(ulong)puVar17 & 0xffffffff,0x80);
      uVar7 = uVar12 + 0x28c;
      func_0x0071b098((ulong)auStack_6ac & 0xffffffff,(ulong)puVar18 & 0xffffffff,0x100);
      func_0x0071b098(uVar12 & 0xffffffff,(ulong)&uStack_838 & 0xffffffff,0x28c);
      if (iVar24 != (int)uVar7) {
        if (((long)(puVar14 + param_3 * -0xa3) + (-0x28c - uVar12) >> 2 & 1) != 0) {
          bStack_833 = bStack_31b;
          uStack_834 = uStack_31c;
          uStack_838 = uVar5;
          func_0x0071b098((ulong)auStack_832 & 0xffffffff,(ulong)puVar16 & 0xffffffff,0x80);
          func_0x0071b098((ulong)auStack_7b2 & 0xffffffff,(ulong)puVar15 & 0xffffffff,0x80);
          uStack_730 = uStack_218;
          func_0x0071b098((ulong)auStack_72c & 0xffffffff,(ulong)puVar17 & 0xffffffff,0x80);
          func_0x0071b098((ulong)auStack_6ac & 0xffffffff,(ulong)puVar18 & 0xffffffff,0x100);
          goto LAB_0086a284;
        }
        do {
          uStack_834 = uStack_31c;
          bStack_833 = bStack_31b;
          uStack_838 = uVar5;
          func_0x0071b098((ulong)auStack_832 & 0xffffffff,(ulong)puVar16 & 0xffffffff,0x80);
          func_0x0071b098((ulong)auStack_7b2 & 0xffffffff,(ulong)puVar15 & 0xffffffff,0x80);
          uStack_730 = uStack_218;
          func_0x0071b098((ulong)auStack_72c & 0xffffffff,(ulong)puVar17 & 0xffffffff,0x80);
          func_0x0071b098((ulong)auStack_6ac & 0xffffffff,(ulong)puVar18 & 0xffffffff,0x100);
          func_0x0071b098(uVar7 & 0xffffffff,(ulong)&uStack_838 & 0xffffffff,0x28c);
          uStack_834 = uStack_31c;
          bStack_833 = bStack_31b;
          uStack_838 = uVar5;
          func_0x0071b098((ulong)auStack_832 & 0xffffffff,(ulong)puVar16 & 0xffffffff,0x80);
          func_0x0071b098((ulong)auStack_7b2 & 0xffffffff,(ulong)puVar15 & 0xffffffff,0x80);
          uStack_730 = uStack_218;
          func_0x0071b098((ulong)auStack_72c & 0xffffffff,(ulong)puVar17 & 0xffffffff,0x80);
          func_0x0071b098((ulong)auStack_6ac & 0xffffffff,(ulong)puVar18 & 0xffffffff,0x100);
          uVar12 = uVar7;
          uVar7 = uVar7 + 0x28c;
LAB_0086a284:
          uVar10 = uVar7 & 0xffffffff;
          uVar7 = uVar12 + 0x518;
          func_0x0071b098(uVar10,(ulong)&uStack_838 & 0xffffffff,0x28c);
        } while (iVar24 != (int)uVar7);
      }
    }
  }
  goto LAB_008694a0;
LAB_00869ac0:
  iVar24 = (int)uVar12;
  while (iVar24 != 0) {
    uVar22 = param_2 & 0xffffffff;
    puVar3 = (undefined4 *)(uVar12 & 0xffffffff);
    param_2 = param_2 + 0x28c;
    uVar2 = *(undefined1 *)(uVar22 + 5);
    *(undefined1 *)(puVar3 + 1) = *(undefined1 *)(uVar22 + 4);
    *(undefined1 *)((long)puVar3 + 5) = uVar2;
    *puVar3 = uVar5;
    func_0x0071b098((long)puVar3 + 6,uVar22 + 6,0x80);
    func_0x0071b098((long)puVar3 + 0x86,uVar22 + 0x86,0x80);
    puVar3[0x42] = *(undefined4 *)(uVar22 + 0x108);
    func_0x0071b098(puVar3 + 0x43,uVar22 + 0x10c,0x80);
    func_0x0071b098(puVar3 + 99,uVar22 + 0x18c,0x100);
    if (uVar23 == (uint)param_2) goto LAB_00869c08;
    uVar12 = uVar12 + 0x28c;
    iVar24 = (int)uVar12;
  }
  param_2 = param_2 + 0x28c;
  if (uVar23 == (uint)param_2) goto LAB_00869c08;
  uVar12 = 0x28c;
  goto LAB_00869ac0;
LAB_00869c08:
  uVar20 = *(uint *)(param_1 + 4);
  uVar12 = (ulong)uVar20;
  if (uVar20 != 0) {
    uVar23 = *(uint *)(param_1 + 8);
    if (uVar20 != uVar23) {
      uVar26 = (int)(((uVar23 - uVar12) - 0x28c & 0xffffffff) >> 2) * 3 & 3;
      (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(ulong)uVar20)
                ((uint *)(ulong)uVar20);
      uVar22 = uVar12 + 0x28c;
      if ((uint)uVar22 != uVar23) {
        if (uVar26 != 0) {
          if (uVar26 != 1) {
            if (uVar26 != 2) {
              (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(uVar22 & 0xffffffff))
                        ((uint *)(uVar22 & 0xffffffff));
              uVar22 = uVar12 + 0x518;
            }
            (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(uVar22 & 0xffffffff))
                      ((uint *)(uVar22 & 0xffffffff));
            uVar22 = uVar22 + 0x28c;
          }
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(uVar22 & 0xffffffff))
                    ((uint *)(uVar22 & 0xffffffff));
          uVar22 = uVar22 + 0x28c;
          if ((uint)uVar22 == uVar23) goto LAB_00869dc8;
        }
        do {
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*(uint *)(uVar22 & 0xffffffff))
                    ((uint *)(uVar22 & 0xffffffff));
          puVar14 = (uint *)(uVar22 + 0x28c & 0xffffffff);
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*puVar14)(puVar14);
          puVar14 = (uint *)(uVar22 + 0x518 & 0xffffffff);
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*puVar14)(puVar14);
          puVar14 = (uint *)(uVar22 + 0x7a4 & 0xffffffff);
          (*(code *)(ulong)*(uint *)(ulong)*(uint *)(ulong)*puVar14)(puVar14);
          uVar22 = uVar22 + 0xa30;
        } while ((uint)uVar22 != uVar23);
      }
    }
LAB_00869dc8:
    func_0x0071b0c8(*(undefined4 *)(param_1 + 4));
    iVar19 = ((int)param_3 + ((int)(uVar23 - uVar20) >> 2) * 0x451ab30b) * 0x28c;
  }
  iVar24 = (int)uVar7;
  *(int *)(param_1 + 4) = iVar24;
  *(int *)(param_1 + 0xc) = iVar24 + (int)(uVar10 * 0x28c);
  *(int *)(param_1 + 8) = iVar24 + iVar19;
LAB_008694a0:
  *(undefined4 *)((ulong)&uStack_320 & 0xffffffff) = uVar4;
  return;
}



// ===== function 0x87e8a0 =====

void FUN_0087e8a0(long param_1,undefined8 param_2)

{
  *(int *)(param_1 + 0x1744) = (int)((ulong)param_2 >> 0x20);
  *(int *)(param_1 + 0x1748) = (int)param_2;
  return;
}



