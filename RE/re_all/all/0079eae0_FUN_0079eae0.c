
void __thiscall
FUN_0079eae0(uint3 param_1,undefined4 param_2,uint *param_3,int param_4,short param_5,short param_6,
            uint *param_7)

{
  short sVar1;
  uint uVar2;
  short sVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  undefined4 uStack_4;
  
  psVar4 = (short *)param_3;
  sVar3 = param_6 + param_5 * 2;
  uStack_4 = (uint)param_1;
  _param_6 = param_4 + 8 >> 4;
  if (0 < _param_6) {
    param_3 = param_7;
    do {
      if (0 < (int)*param_3) {
        uVar2 = *param_3 & 0x1f;
        if (5 < uVar2) {
          uVar2 = 6;
        }
        uStack_4._0_3_ = CONCAT12((&DAT_00837e28)[uVar2 + sVar3 * 7],(undefined2)uStack_4);
        iVar6 = 0x10;
        psVar5 = psVar4;
        do {
          if (0 < *psVar5) {
            sVar1 = FUN_007a2170(param_2,(int)&uStack_4 + 2,8);
            *psVar5 = (sVar1 * 2 + -1) * *psVar5;
          }
          psVar5 = psVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      psVar4 = psVar4 + 0x10;
      param_3 = param_3 + 1;
      _param_6 = _param_6 + -1;
    } while (_param_6 != 0);
  }
  return;
}

