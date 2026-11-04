
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_0064bcf0(float *param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float local_c [3];
  
  pfVar1 = param_1;
  if (param_1[0x12] == 0.0) {
    fVar2 = (float)FUN_006507d0(0x46cc);
    pfVar1[0x12] = fVar2;
    if (fVar2 == 0.0) {
      FUN_006512e0(*(undefined4 *)((int)*pfVar1 + 0x274),"initCIELabConversion",
                   s_No_space_for_CIE_L_a_b__>RGB_con_00a065f4);
      return (undefined1 *)0x0;
    }
  }
  FUN_00651280(*pfVar1,0x13e,&param_1);
  local_c[1] = 100.0;
  local_c[0] = (*param_1 / param_1[1]) * _DAT_007d1038;
  local_c[2] = (((_DAT_00804108 - *param_1) - param_1[1]) / param_1[1]) * _DAT_007d1038;
  iVar3 = FUN_00652fb0(pfVar1[0x12],&DAT_00804950,local_c);
  if (iVar3 < 0) {
    FUN_006512e0(*(undefined4 *)((int)*pfVar1 + 0x274),"initCIELabConversion",
                 s_Failed_to_initialize_CIE_L_a_b___00a065bc);
    FUN_006507e0(pfVar1[0x12]);
    return (undefined1 *)0x0;
  }
  return &LAB_0064bdd0;
}

