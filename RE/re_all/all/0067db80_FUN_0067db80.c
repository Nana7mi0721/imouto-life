
char FUN_0067db80(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0xffff;
  if (param_1[3] - 5U < 0xffff) {
    uVar6 = param_1[3] - 5U;
  }
  do {
    uVar3 = param_1[0x1d];
    if (uVar3 < 2) {
      FUN_0067d900(param_1);
      uVar3 = param_1[0x1d];
      if (uVar3 == 0) {
        if (param_2 == 0) {
          return '\0';
        }
        param_1[0x5ad] = 0;
        if (param_2 == 4) {
          iVar5 = param_1[0x17];
          if (iVar5 < 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = param_1[0xe] + iVar5;
          }
          FUN_0067f720(param_1,iVar4,param_1[0x1b] - iVar5,1);
          param_1[0x17] = param_1[0x1b];
          FUN_0067d730(*param_1);
          return (*(int *)(*param_1 + 0x10) != 0) + '\x02';
        }
        iVar5 = param_1[0x17];
        if (iVar5 < param_1[0x1b]) {
          if (iVar5 < 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = param_1[0xe] + iVar5;
          }
          FUN_0067f720(param_1,iVar4,param_1[0x1b] - iVar5,0);
          param_1[0x17] = param_1[0x1b];
          FUN_0067d730(*param_1);
          if (*(int *)(*param_1 + 0x10) == 0) {
            return '\0';
          }
        }
        return '\x01';
      }
    }
    iVar5 = param_1[0x1b];
    param_1[0x1d] = 0;
    param_1[0x1b] = iVar5 + uVar3;
    iVar4 = param_1[0x17];
    uVar2 = param_1[0x1b];
    uVar1 = iVar4 + uVar6;
    if ((iVar5 + uVar3 == 0) || (uVar1 <= uVar2)) {
      param_1[0x1b] = uVar1;
      param_1[0x1d] = uVar2 - uVar1;
      if (iVar4 < 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = param_1[0xe] + iVar4;
      }
      FUN_0067f720(param_1,iVar5,uVar1 - iVar4,0);
      param_1[0x17] = param_1[0x1b];
      FUN_0067d730(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return '\0';
      }
    }
    iVar5 = param_1[0x17];
    if (param_1[0xb] - 0x106U <= (uint)(param_1[0x1b] - iVar5)) {
      if (iVar5 < 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = param_1[0xe] + iVar5;
      }
      FUN_0067f720(param_1,iVar4,param_1[0x1b] - iVar5,0);
      param_1[0x17] = param_1[0x1b];
      FUN_0067d730(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return '\0';
      }
    }
  } while( true );
}

