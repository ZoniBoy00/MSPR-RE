// ===== function 0x10f290 =====

char FUN_0010f290(ulong param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  char cVar3;
  uint *puVar4;
  
  if ((int)param_1 == 0) {
    cVar3 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*(uint *)(ulong)uRam00000000000000f8 +
                                                      0x30))((uint *)(ulong)uRam00000000000000f8);
    if (cVar3 == '\0') {
      return '\0';
    }
    cVar3 = *(char *)(param_1 + 0x94);
  }
  else {
    uVar2 = func_0x0071be48(param_1 & 0xffffffff,uRam0000000000e94c90,uRam0000000000e94c94,0);
    puVar4 = (uint *)(ulong)*(uint *)((uVar2 & 0xffffffff) + 0xf8);
    cVar3 = (*(code *)(ulong)*(uint *)(ulong)*(uint *)((ulong)*puVar4 + 0x30))(puVar4);
    if (cVar3 == '\0') {
      return '\0';
    }
    cVar3 = *(char *)(param_1 + 0x94);
  }
  if (cVar3 == '\0') {
    cVar3 = func_0x00109170(param_1 & 0xffffffff);
    if (cVar3 != '\0') {
      func_0x00108d40(param_1 + 0x98 & 0xffffffff);
      uVar1 = uRam0000000000e94c98 /* 'MatchMaking can start. There are %d players' */;
      *(undefined4 *)((ulong)uRam0000000000e94c88 + 0x24) = 0;
      func_0x00108760(uVar1,(long)*(int *)(param_1 + 0xa0));
      return cVar3;
    }
  }
  else if (((1 < *(int *)(param_1 + 0xa0)) && (*(int *)(param_1 + 0xa4) <= *(int *)(param_1 + 0xa0))
           ) && (cVar3 = func_0x00108f68(), cVar3 != '\0')) {
    func_0x00108d40(param_1 + 0x98 & 0xffffffff);
    uVar1 = uRam0000000000e94c98 /* 'MatchMaking can start. There are %d players' */;
    *(undefined4 *)((ulong)uRam0000000000e94c88 + 0x24) = 0;
    func_0x00108760(uVar1,(long)*(int *)(param_1 + 0xa0));
    return '\x01';
  }
  return '\0';
}



// ===== function 0x847ef8 =====

void FUN_00847ef8(undefined8 param_1,int *param_2)

{
  if ((param_2[1] == 3) && (*param_2 == 0x5b)) {
    func_0x0027c1b8(uRam0000000000e98fd4 /* 'NoMatch Found Room gone to NoMatch' */);
    return;
  }
  return;
}



