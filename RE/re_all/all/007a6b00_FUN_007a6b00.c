
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_007a6b00(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  float10 fVar2;
  undefined4 uStack_5c;
  undefined1 auStack_58 [4];
  int aiStack_54 [8];
  undefined1 auStack_34 [4];
  int aiStack_30 [2];
  float afStack_28 [2];
  undefined1 auStack_20 [4];
  int aiStack_1c [3];
  
  aiStack_1c[2] = 0x7a6b1a;
  iVar1 = param_2 * -4;
  aiStack_1c[2 - param_2] = param_6;
  aiStack_1c[1 - param_2] = param_3;
  aiStack_1c[-param_2] = param_2;
  *(int **)(auStack_20 + iVar1) = aiStack_1c + (3 - param_2);
  afStack_28[1 - param_2] = 1.1242375e-38;
  fVar2 = (float10)FUN_007a8200();
  afStack_28[1 - param_2] = (float)param_7;
  afStack_28[-param_2] = (float)fVar2;
  aiStack_30[1 - param_2] = param_2;
  aiStack_30[-param_2] = param_1;
  *(int **)(auStack_34 + iVar1) = aiStack_1c + (3 - param_2);
  aiStack_54[7 - param_2] = 0x7a6b41;
  FUN_007a6b70();
  aiStack_54[7 - param_2] = param_4;
  aiStack_54[6 - param_2] = param_3;
  aiStack_54[5 - param_2] = param_5;
  aiStack_54[4 - param_2] = 0xffffffff;
  aiStack_54[3 - param_2] = param_2;
  aiStack_54[2 - param_2] = param_1;
  aiStack_54[1 - param_2] = 0x7a6b56;
  FUN_007a68d0();
  aiStack_54[1 - param_2] = param_5;
  aiStack_54[-param_2] = param_2;
  *(int **)(auStack_58 + iVar1) = aiStack_1c + (3 - param_2);
  *(undefined4 *)(auStack_58 + iVar1 + -4) = 0x7a6b5e;
  FUN_007a6a90();
  return;
}

