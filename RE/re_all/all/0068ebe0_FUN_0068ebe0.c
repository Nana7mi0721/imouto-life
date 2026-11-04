
int FUN_0068ebe0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  int local_4;
  
  if (param_3 < param_4) {
    local_4 = param_3 * 2;
    piVar5 = (int *)(param_3 * 0x20 + 0xc + param_2);
    while( true ) {
      if (param_4 < local_4) {
        piVar2 = (int *)FUN_0068ed60(param_2,param_3);
      }
      else {
        piVar2 = (int *)FUN_0068ed20();
      }
      if (piVar2 == (int *)0x0) break;
      piVar1 = piVar5 + -3;
      piVar5[-2] = piVar2[1];
      *piVar5 = piVar2[3];
      piVar5[2] = piVar2[5];
      *piVar1 = *piVar2;
      piVar5[-1] = piVar2[2];
      piVar5[1] = piVar2[4];
      iVar3 = (piVar2[1] - *piVar2) * 0x10;
      iVar6 = (piVar2[3] - piVar2[2]) * 0xc;
      cVar4 = iVar3 <= iVar6;
      if (!(bool)cVar4) {
        iVar6 = iVar3;
      }
      if (iVar6 < (piVar2[5] - piVar2[4]) * 8) {
        cVar4 = '\x02';
      }
      if (cVar4 == '\0') {
        iVar6 = (*piVar2 + piVar2[1]) / 2;
        piVar2[1] = iVar6;
        *piVar1 = iVar6 + 1;
      }
      else if (cVar4 == '\x01') {
        iVar6 = (piVar2[3] + piVar2[2]) / 2;
        piVar2[3] = iVar6;
        piVar5[-1] = iVar6 + 1;
      }
      else if (cVar4 == '\x02') {
        iVar6 = (piVar2[4] + piVar2[5]) / 2;
        piVar2[5] = iVar6;
        piVar5[1] = iVar6 + 1;
      }
      FUN_0068e790(param_1,piVar2);
      FUN_0068e790(param_1,piVar1);
      param_3 = param_3 + 1;
      local_4 = local_4 + 2;
      piVar5 = piVar5 + 8;
      if (param_4 <= param_3) {
        return param_3;
      }
    }
  }
  return param_3;
}

