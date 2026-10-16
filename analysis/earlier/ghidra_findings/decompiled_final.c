// ==== function @ 0x204a04 (FUN_00204a04) ====
//   0x208dd4: Checking for downloaded ghost for account %s

/* WARNING: Control flow encountered bad instruction data */

void FUN_00204a04(void)

{
  long unaff_r2;
  long unaff_r28;
  undefined4 *unaff_r31;
  
  *unaff_r31 = *(undefined4 *)(unaff_r2 + 0x47c);
  FUN_00752c90();
  FUN_00752d40();
  if (*(int *)(unaff_r28 + 4) != 0) {
    func_0x00752d44(*(int *)(unaff_r28 + 4));
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ==== function @ 0xb264ec (FUN_00b264ec) ====
//   0xb26fac: bestTime

/* WARNING: Control flow encountered bad instruction data */

void FUN_00b264ec(void)

{
  undefined8 uVar1;
  long unaff_r2;
  ulong in_r10;
  undefined8 unaff_r17;
  
  *(undefined4 *)(in_r10 & 0xffffffff) = *(undefined4 *)(unaff_r2 + -0x1940);
  uVar1 = TBLr;
  trapWord(4,unaff_r17,0x2b00);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ==== function @ 0xb2eddc (FUN_00b2eddc) ====
//   0xb311f0: ving the online ghost data

/* WARNING: Control flow encountered bad instruction data */

void FUN_00b2eddc(uint *param_1)

{
  int unaff_r24;
  
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_1 + 0x18))(param_1,(long)unaff_r24);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ==== function @ 0xb39760 (FUN_00b39760) ====
//   0xb3be98: line.ranked.gamesplayed

/* WARNING: Control flow encountered bad instruction data */

void FUN_00b39760(ulong param_1,uint *param_2)

{
  undefined4 uVar1;
  long unaff_r2;
  
  (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_2 + 8))(param_2,0,2,param_1 & 0xffffffff)
  ;
  if (*(int *)(param_1 + 0x1db0) != 0) {
    uVar1 = *(undefined4 *)(unaff_r2 + -0x1694);
    func_0x00cc3f20(param_2,uVar1,4,*(int *)(param_1 + 0x1db0));
    func_0x00cc3f20(param_2,uVar1,4,*(undefined4 *)(param_1 + 0x1db4));
    func_0x00cc3f20(param_2,uVar1,4,*(undefined4 *)(param_1 + 0x1db8));
    func_0x00cc3f20(param_2,uVar1,4,*(undefined4 *)(param_1 + 0x1dbc));
  }
  if (-1 < *(int *)(param_1 + 0x1dac)) {
    (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*param_2 + 0xc))
              (param_2,*(undefined4 *)(unaff_r2 + -0x1690),4,*(undefined4 *)(param_1 + 0x1da4),
               (long)(*(int *)(param_1 + 0x1da8) << 3),(long)(*(int *)(param_1 + 0x1dac) << 3));
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



