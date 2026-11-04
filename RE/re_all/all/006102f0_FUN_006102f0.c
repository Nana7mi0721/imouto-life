
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_006102f0(int *param_1,float param_2)

{
  float10 fVar1;
  float *unaff_retaddr;
  float fStack00000008;
  float fStack0000000c;
  float *in_stack_00000014;
  float *in_stack_00000018;
  float fVar2;
  float fVar3;
  float fVar4;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_8;
  float *pfStack_4;
  
  (**(code **)(*param_1 + 4))(param_2,in_stack_00000014,in_stack_00000018);
  fVar3 = in_stack_00000018[1];
  fVar2 = *in_stack_00000018;
  fStack00000008 = in_stack_00000014[1];
  fVar4 = in_stack_00000018[2];
  fStack0000000c = *in_stack_00000014;
  fStack_8 = in_stack_00000014[2];
  fStack_24 = param_2 * pfStack_4[1];
  fStack_20 = param_2 * *pfStack_4;
  pfStack_4 = (float *)(param_2 * pfStack_4[2]);
  FUN_005fc500(&fStack_20,&fStack_24,&pfStack_4);
  if (fStack_1c <= _DAT_007d5344) {
    fStack0000000c = fStack_1c + fStack0000000c;
  }
  else {
    fVar2 = fStack_1c + fVar2;
  }
  if (fStack_18 <= _DAT_007d5344) {
    fStack00000008 = fStack_18 + fStack00000008;
  }
  else {
    fVar3 = fStack_18 + fVar3;
  }
  if (fStack_14 <= _DAT_007d5344) {
    fStack_8 = fStack_14 + fStack_8;
  }
  else {
    fVar4 = fStack_14 + fVar4;
  }
  pfStack_4 = (float *)(unaff_retaddr[2] * unaff_retaddr[2] +
                       unaff_retaddr[1] * unaff_retaddr[1] + *unaff_retaddr * *unaff_retaddr);
  fVar1 = (float10)(**(code **)(*param_1 + 0xc))();
  *in_stack_00000014 = fStack0000000c;
  in_stack_00000014[1] = fStack00000008;
  in_stack_00000014[2] = fStack_8;
  in_stack_00000014[3] = 0.0;
  *in_stack_00000018 = fVar2;
  in_stack_00000018[1] = fVar3;
  in_stack_00000018[2] = fVar4;
  in_stack_00000018[3] = 0.0;
  fVar1 = SQRT((float10)(float)pfStack_4) * fVar1 * (float10)param_2;
  *in_stack_00000014 = (float)((float10)*in_stack_00000014 - fVar1);
  in_stack_00000014[1] = (float)((float10)in_stack_00000014[1] - fVar1);
  in_stack_00000014[2] = (float)((float10)in_stack_00000014[2] - fVar1);
  *in_stack_00000018 = (float)(fVar1 + (float10)*in_stack_00000018);
  in_stack_00000018[1] = (float)(fVar1 + (float10)in_stack_00000018[1]);
  in_stack_00000018[2] = (float)(fVar1 + (float10)in_stack_00000018[2]);
  return;
}

