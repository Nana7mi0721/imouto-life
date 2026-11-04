
undefined4 FUN_006c522d(int param_1,uint param_2,int param_3,uint param_4)

{
  uint in_EAX;
  uint uVar1;
  undefined4 uVar2;
  char extraout_CL;
  uint extraout_ECX;
  int extraout_ECX_00;
  int iVar3;
  int extraout_ECX_01;
  bool bVar4;
  short in_FPUControlWord;
  float10 extraout_ST0;
  float10 fVar5;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 fVar6;
  unkbyte10 in_ST7;
  undefined1 local_78 [20];
  undefined4 uStack_64;
  undefined1 auStack_e [10];
  short local_4;
  undefined2 uStack_2;
  
  _local_4 = CONCAT22((short)(in_EAX >> 0x10),in_FPUControlWord);
  uVar1 = in_EAX;
  if (in_FPUControlWord != 0x27f) {
    auStack_e._6_4_ = 0x6c5241;
    in_EAX = FUN_00507225();
    uVar1 = extraout_ECX;
  }
  bVar4 = (uVar1 & 0x7ff00000) == 0x7ff00000;
  if (bVar4) {
    if ((in_EAX & 0xfffff) == 0 && param_3 == 0) {
      auStack_e._6_4_ = 0x6c530a;
      fVar5 = (float10)__fload_withFB();
      iVar3 = extraout_ECX_01;
      fVar6 = extraout_ST1_01;
      goto LAB_006c530a;
    }
    auStack_e._6_4_ = 0x6c52cd;
    fVar5 = (float10)__fload_withFB();
    if ((param_4 & 0x80000) == 0) {
      iVar3 = extraout_ECX_00 + 1;
      fVar6 = extraout_ST1_00;
      goto LAB_006c530a;
    }
LAB_006c52d7:
    uVar2 = 1;
  }
  else {
    auStack_e._6_4_ = 0x6c525c;
    uVar1 = __fload_withFB();
    if (!bVar4) {
      if (((uVar1 & 0x7ff00000) != 0) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) {
        fVar5 = extraout_ST0;
        if ((param_2 & 0x80000000) != 0) {
          auStack_e._6_4_ = 0x6c53d4;
          fVar5 = (float10)FUN_006c53f2();
          fVar5 = -fVar5;
          if (extraout_CL == '\0') {
            uVar2 = 1;
            goto LAB_006c52a5;
          }
        }
        log2(fVar5);
        auStack_e._6_4_ = 0x6c5281;
        uVar2 = FUN_00507210();
        if (DAT_00a1fbb8 == 0) {
          uVar2 = FUN_005072f9();
          return uVar2;
        }
        return uVar2;
      }
      if ((param_4 & 0x7fffffff) == 0 && param_3 == 0) {
        return 0;
      }
      auStack_e._6_4_ = 0x6c538c;
      uVar2 = FUN_006c53f2();
      if ((param_4 & 0x80000000) == 0) {
        return uVar2;
      }
      uVar2 = 2;
      goto LAB_006c52a5;
    }
    iVar3 = 0;
    fVar5 = extraout_ST0;
    fVar6 = extraout_ST1;
LAB_006c530a:
    if (((param_2 & 0x7ff00000) == 0x7ff00000) && ((param_2 & 0xfffff) != 0 || param_1 != 0)) {
      if ((param_2 & 0x80000) != 0) goto LAB_006c52d7;
    }
    else if (iVar3 == 0) {
      uStack_64 = 0x6c5338;
      auStack_e = (undefined1  [10])in_ST7;
      iVar3 = __powhlp((double)fVar5,(double)fVar6,local_78);
      if (iVar3 == 0) {
        return 0;
      }
      uVar2 = 1;
      goto LAB_006c52a5;
    }
    uVar2 = 7;
  }
LAB_006c52a5:
  if (DAT_00a1fbb8 == 0) {
    auStack_e._6_4_ = 0x6c52c2;
    uVar2 = FUN_005071b0();
    return uVar2;
  }
  return uVar2;
}

