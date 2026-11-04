
uint FUN_0052dcb0(undefined4 param_1,uint param_2,int param_3,undefined4 *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar2 = param_4[2];
  uVar5 = param_4[4];
  uVar3 = param_4[3];
  uVar4 = param_4[5];
  if ((uVar2 != uVar5) || (uVar3 != uVar4)) {
    uVar6 = uVar3 + CARRY4(param_2 * param_3,uVar2);
    if ((uVar4 <= uVar6) && ((uVar4 < uVar6 || (uVar5 < param_2 * param_3 + uVar2)))) {
      param_3 = __aulldiv(uVar5 - uVar2,(uVar4 - uVar3) - (uint)(uVar5 < uVar2),param_2,0);
    }
    if (param_3 != 0) {
      uVar5 = FUN_00595440(param_1,param_2,param_3,param_4);
      puVar1 = param_4 + 2;
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + uVar5;
      param_4[3] = param_4[3] + (uint)CARRY4(uVar2,uVar5);
      if (uVar5 == 0) {
        return 0;
      }
      return uVar5 / param_2;
    }
  }
  *param_4 = 1;
  return 0;
}

