
undefined4 __fastcall
FUN_00515360(undefined4 param_1,undefined4 param_2,float param_3,float param_4,undefined4 param_5,
            undefined4 param_6,double param_7,int param_8,undefined4 param_9,undefined4 param_10)

{
  ushort in_FPUControlWord;
  
  FUN_00748330(DAT_00a37e58,param_8 + 0x88,(int)ROUND(param_3),(int)ROUND(param_4),(float)param_7,
               (float)(double)CONCAT44(param_6,param_5),(float)(double)CONCAT44(param_6,param_5),
               param_9,param_10,param_2,DAT_00a37e5c,in_FPUControlWord | 0xc00);
  return 0;
}

